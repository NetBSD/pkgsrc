#!/bin/sh

# $NetBSD: pkg_rolling-replace.sh,v 1.1.1.1 2006/12/05 18:23:52 gdt Exp $
#<license>
# Copyright (c) 2006 BBN Technologies Corp.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of BBN Technologies nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY BBN TECHNOLOGIES AND CONTRIBUTORS ``AS IS''
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL BBN TECHNOLOGIES OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Effort sponsored in part by the Defense Advanced Research Projects
# Agency (DARPA) and the Department of the Interior National Business
# Center under agreement number NBCHC050166.
#</license>

# REVIEW NOTATION LEGEND
#   XXX marks things that are broken/kludgy
#   TODO marks things that need to be done
#   FIXED marks items fixed, needs review and deletion of FIXED comment

# Items to be completed for initial release:

# TODO: move bulk of help into a real man page.

# Items for future work (some imply changes in pkgsrc, not necessarily here)
#
#   Make a pass over all packages for build depends, and rememeber
# which packages have been so checked.  Check newly unsafe packages.
# The current lazy evaluation can perhaps fail to do things in the
# right order.  Alternatively, explain why the current scheme is safe
# and preferred.
#
#   Consider expansion to update via binary packages.  This raises
# interesting questions about ABIs and binary builds
#
#   Deal with conflicts in a smarter way, perhaps more automatically.
# This is hard because just removing packages is not ok.
#
#   Handle foo being split into foo and foo-share.  Now, make replace
# of foo pulls in foo-share which conflicts with foo.  This needlessly
# loses.
#
#   Parse mk.conf for PKGSRCDIR, etc.

test -n "$PKG_DBDIR" || PKG_DBDIR=/var/db/pkg
test -n "$PKGSRCDIR" || PKGSRCDIR=/usr/pkgsrc

unset PKG_PATH || true  #or pkgsrc makefiles will complain

MAKE=make
# XXX Find BSD make at package build time.
UNAME=`uname`
case "$UNAME" in
    Darwin)
    MAKE=bmake
    ;;
esac

usage()
{
    echo "Usage: pkg_rolling-replace [opts]
        -h         This help
        -n         Don't actually do make replace
        -u         Update mismatched packages
        -v         Verbose
        -x <pkg>   exclude <pkg> from update check

pkg_rolling-replace does 'make replace' on one package at a time,
tsorting the packages being replaced according to their
interdependencies, which avoids most duplicate rebuilds.

pkg_rolling-replace can be used in one of two ways:

    - 'make replace' is unsafe in that, if the replaced package's ABI
      changes, its dependent packages may break.  If this happens, run
      'pkg_rolling-replace' (no arguments) to rebuild them against the
      new version.

    - 'pkg_chk -u' will delete all your mismatched (outdated)
      packages, then reinstall them one at a time, leaving you without
      those packages in the meantime.  'pkg_rolling-replace -u' will
      instead upgrade them in place, allowing you to keep using your
      system in the meantime (maybe...if you're lucky...because
      pkg_rolling-replace replaces the \"deepest\" dependency first,
      things could still break if that happens to be a fundamental
      library whose ABI has changed).
"
    exit 1
}

# pkg_rolling-replace's output is intermingled with pkgsrc make
# output.  Thus, we use a different prefix.  pkgsrc uses '===>' for
# major steps, and '=>' for minor ones.  Thus, we use 'RR>'.

OPI='RR>'
OPC='rr>' # continuation


# Echo the names of packages needing updates, versions stripped.  This
# has been tested with pkg_chk 1.76.  Older versions are not
# supported.  Newer versions may or may not work (patches welcome).
check_packages_mismatched()
{
    pkg_chk -u -q | while read line; do
        # duplicate output of pkg_chk to stderr (bypass $(...) or `...`)
        echo "${OPC} $line" > /dev/stderr
	# Look for the first thing that looks like pkg-version rather
	# than category/pkg and remove the version.
        for word in $line; do
            if [ "$(echo $word | egrep '^[^/]+-[0-9][^/]*$')" ]; then
                echo $word | sed 's/-[0-9].*//'
                break  #done with this line
            fi
        done
    done
}

# usage: check_packages_w_flag flag
# echo packages with flag=YES
check_packages_w_flag()
{
    _flag=$1; shift
    for pkgver in $(pkg_info -e '*'); do
        if pkg_info -Bq $pkgver \
                | egrep "^$_flag=[Yy][Ee][Ss]" > /dev/null; then
            echo $pkgver | sed 's/-[0-9].*//'
        fi
    done
}

# echo dep->pkg edges for all installed packages
depgraph_installed()
{
    for pkgver in $(pkg_info -e '*'); do
        pkg=$(echo $pkgver | sed 's/-[0-9].*//')
	# Include $pkg as a node without dependencies in case it has none.
        echo $pkg $pkg
        for depver in $(pkg_info -Nq $pkg); do
            dep=$(echo $depver | sed 's/-[0-9].*//')
            echo $dep $pkg
        done
    done
}

# usage: who_requires pkg --in-graph DEPGRAPH
who_requires()
{
    _target=$1; shift
    test "$1" = '--in-graph' && shift || return $((false))

    while [ $# -gt 0 ]; do
        _dep=$1; _pkg=$2; shift 2;
        if [ $_dep = $_target -a $_dep != $_pkg ]; then
            echo $_pkg
        fi
    done
}

# usage: is_member x list
# return true (0) if x appears in list, false (1) otherwise
is_member()
{
    _x="$1"; shift;
    while [ $# -gt 0 -a "$1" != "$_x" ]; do
        shift
    done

    test $# -gt 0
}

# usage: exclude list1 --from list2
# echo list2 with items from list1 excluded
exclude()
{
    _excl=
    while [ $# -gt 0 -a $1 != "--from" ]; do
        _excl="$_excl $1"
        shift
    done
    if [ $# -gt 0 ]; then
        shift  #discard '--from'
    fi
    while [ $# -gt 0 ]; do
        is_member $1 $_excl || echo $1
        shift
    done
}

# usage: uniquify list
# just does sort -u on list (equiv. to sort | uniq)
# CAUTION: reorders list
uniqify()
{
    for _x in $*; do echo $_x; done | sort -u
}

verbose()
{
    if [ -n "$opt_v" ]; then
        echo "$@"
    fi
}

vsleep()
{
    if [ -n "$opt_v" ]; then
        sleep $1
    fi
}

######################################################################
##
## main()
##

EXCLUDE=

args=$(getopt hnuvx: $*)
if [ $? -ne 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# -gt 0 ]; do
    case "$1" in
        -h) opt_h=1 ;;
        -n) opt_n=1 ;;
        -u) opt_u=1 ;;
        -v) opt_v=1 ;;
        -x) EXCLUDE="$EXCLUDE $(echo $2 | sed 's/,/ /g')" ; shift ;;
        --) shift; break ;;
    esac
    shift
done

if [ -n "$opt_h" ]; then
    usage
fi

MISMATCH_TODO=
if [ -n "$opt_u" ]; then
    echo "${OPI} Checking for mismatched installed packages using pkg_chk"
    MISMATCH_TODO=$(check_packages_mismatched)
    echo "${OPI} Excluding the following mismatched packages:"
    echo "${OPC} EXCLUDE=[$EXCLUDE]"
    MISMATCH_TODO=$(exclude $EXCLUDE --from $MISMATCH_TODO)
fi

echo "${OPI} Checking for rebuild-requested installed packages (rebuild=YES)"
REBUILD_TODO=$(check_packages_w_flag 'rebuild')

echo "${OPI} Checking for unsafe installed packages (unsafe_depends=YES)"
UNSAFE_TODO=$(check_packages_w_flag 'unsafe_depends')

# DEPGRAPH_INSTALLED is rebuilt each round.  DEPGRAPH_SRC will collect
# edges that we discover using 'make show-depends', but that weren't
# listed as depends by the installed version of a package, and
# DEPENDS_CHECKED lists packages for which we've already done that
# check.
DEPGRAPH_INSTALLED=
DEPGRAPH_SRC=
DEPENDS_CHECKED=

verbose "${OPI} Packages to rebuild:"
verbose "${OPC} MISMATCH_TODO=[$(echo $MISMATCH_TODO)]"  #strip newlines
verbose "${OPC} REBUILD_TODO=[$(echo $REBUILD_TODO)]"
verbose "${OPC} UNSAFE_TODO=[$(echo $UNSAFE_TODO)]"
vsleep 2

REPLACE_TODO=$(uniqify $MISMATCH_TODO $REBUILD_TODO $UNSAFE_TODO)
depgraph_built=0

while [ -n "$REPLACE_TODO" ]; do
    # don't rebuild depgraph if we continued from new-depends step below
    if [ "$depgraph_built" -eq 0 ]; then
        echo "${OPI} Building dependency graph for installed packages"
        DEPGRAPH_INSTALLED=$(depgraph_installed)
        depgraph_built=1
    fi

    echo "${OPI} Tsorting dependency graph"
    TSORTED=$(echo $DEPGRAPH_INSTALLED $DEPGRAPH_SRC | tsort)
    for pkg in $TSORTED; do
        if is_member $pkg $REPLACE_TODO; then
            break;
        fi
    done
    pkgdir=$(pkg_info -Bq $pkg | awk -F= '/PKGPATH=/{print $2}')
    echo "${OPI} Selecting $pkg ($pkgdir) as next package to replace"
    sleep 1

    # Newer versions in pkgsrc sometimes have more depends than are
    # recorded for the installed version (this is entirely to be
    # expected as packages are split, renamed, and add new features).
    # When this happens, add the new edges to the graph and re-tsort.
    # Don't re-tsort if the new edges were already installed once
    # (otherwise we'll go into a loop).

    # XXX I'm not sure that DEPENDS_CHECKED is necessary, or whether
    # simply ignoring new deps that aren't in $REPLACE_TODO would have
    # been sufficient.  The DEPENDS_CHECKED approach causes one extra
    # tsort in some cases, which isn't overly expensive.

    # XXX After tsorting and choosing what to 'make replace', we
    # filter out packages that aren't already installed and marked for
    # replacement.  This is safe, since uninstalled depends will be
    # pulled in automatically by 'make replace'; but in rare cases it
    # might be non-optimal, leading to a duplicate rebuild that we
    # would have avoided had we selected the uninstalled package in
    # tsorted order and run 'make install' on it.  This seems like
    # such a rare case that the added complexity isn't worth it.

    if ! is_member $pkg $DEPENDS_CHECKED; then
	echo "${OPI} Checking if $pkg has new depends..."
	OLD_DEPENDS=$(pkg_info -Nq $pkg | sed 's/-[0-9].*[[:>:]]//g')
	NEW_DEPENDS=
	cd "$PKGSRCDIR/$pkgdir"
	bdeps=$(${MAKE} show-depends VARNAME=BUILD_DEPENDS)
	rdeps=$(${MAKE} show-depends)
	for depver in $bdeps $rdeps; do
	    dep=$(echo $depver | sed -e 's/-[0-9].*//' -e 's/[<>]=[0-9].*//' \
		-e 's/-[][].*//')
	    if ! is_member $dep $OLD_DEPENDS $NEW_DEPENDS; then
		NEW_DEPENDS="$NEW_DEPENDS $dep"
		DEPGRAPH_SRC="$DEPGRAPH_SRC $dep $pkg"
	    fi
	done
	DEPENDS_CHECKED="$DEPENDS_CHECKED $pkg"
	if [ -n "$NEW_DEPENDS" ]; then
	    echo "${OPI} $pkg has the following new depends (need to re-tsort):"
	    echo "${OPC} [$(echo $NEW_DEPENDS)]"
	    sleep 2
	    continue
	fi
    fi

    # Do make replace, with clean before, and package and clean afterwards.
    echo "${OPI} Replacing $(pkg_info -e $pkg)"
    FAIL=
    if [ -z "$opt_n" ]; then
	cd "$PKGSRCDIR/$pkgdir" \
	    && ${MAKE} clean && ${MAKE} replace && ${MAKE} package && ${MAKE} clean \
	    || FAIL=1
    else
	echo "cd $PKGSRCDIR/$pkgdir && ${MAKE} clean && ${MAKE} replace && ${MAKE} package && ${MAKE} clean"
    fi
    if [ -n "$FAIL" ]; then
        echo "*** 'make replace' failed for package $pkg."
        echo "*** Please read the errors listed above, fix the problem,"
        echo "*** then re-run pkg_rolling-replace to continue."
        exit 1
    fi
    sleep 1

    # remove just-replaced package from all *_TODO lists
    MISMATCH_TODO=$(exclude $pkg --from $MISMATCH_TODO)
    REBUILD_TODO=$(exclude $pkg --from $REBUILD_TODO)
    UNSAFE_TODO=$(exclude $pkg --from $UNSAFE_TODO)

    echo "${OPI} Re-checking for unsafe installed packages (unsafe_depends=YES)"
    if [ -n "$opt_n" ]; then
	# With -n, the replace didn't happen, and thus the packages that would
	# have been marked unsafe_depends=YES were not.  Add the set that
	# would have been marked so we can watch what pkg_rolling-replace
	# would have done (approximately).
        UNSAFE_TODO=$(uniqify $UNSAFE_TODO \
            $(who_requires $pkg --in-graph $DEPGRAPH_INSTALLED))
        sleep 1
    else
        UNSAFE_TODO=$(check_packages_w_flag 'unsafe_depends')
    fi

    verbose "${OPI} Packages to rebuild:"
    verbose "${OPC} MISMATCH_TODO=[$(echo $MISMATCH_TODO)]"  #strips newlines
    verbose "${OPC} REBUILD_TODO=[$(echo $REBUILD_TODO)]"
    verbose "${OPC} UNSAFE_TODO=[$(echo $UNSAFE_TODO)]"
    vsleep 4

    REPLACE_TODO=$(uniqify $MISMATCH_TODO $REBUILD_TODO $UNSAFE_TODO)
    depgraph_built=0
done

echo "${OPI} No more packages to replace; done."
