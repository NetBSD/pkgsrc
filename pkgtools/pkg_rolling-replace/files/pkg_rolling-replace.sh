#!/bin/sh

# $NetBSD: pkg_rolling-replace.sh,v 1.35 2015/04/14 11:40:31 wiz Exp $
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

# Substituted by pkgsrc at pre-configure time.
MAKE="@MAKE@"
AWK="@AWK@"

if [ -z "$MAKECONF" ] ; then
    for mkconf in "@MAKECONF@" "@PREFIX@/etc/mk.conf" /etc/mk.conf ; do
	if [ -f "$mkconf" ] ; then
	    MAKECONF="$mkconf"
	    break
	fi
    done
fi
if [ -z "$MAKECONF" -o ! -f "$MAKECONF" ] ; then
    MAKECONF=/dev/null
fi
test -f "$MAKECONF" && test -z "$PKGSRCDIR" && PKGSRCDIR="` \
    printf '.include "%s"\n_print_pkgsrcdir:\n\t@echo "${PKGSRCDIR}"\n' \
    "$MAKECONF" | "$MAKE" -f - BSD_PKG_MK=1 _print_pkgsrcdir`"
if [ -z "$PKGSRCDIR" ] ; then
    for dir in . .. ../.. /usr/pkgsrc ; do
	if [ -f "${dir}/mk/bsd.pkg.mk" ]; then
	    case "${dir}" in
	    /*) PKGSRCDIR="${dir}" ;;
	    *)  PKGSRCDIR="$( cd "${dir}" >/dev/null 2>&1 && pwd )" ;;
	    esac
	    break
	fi
    done
fi
test -z "$PKGSRCDIR" && echo >&2 "Please set PKGSRCDIR" && exit 1
test -z "$PKG_CHK" && PKG_CHK="@PKG_CHK@"
test -z "$PKG_INFO" && PKG_INFO="@PKG_INFO_CMD@"

export PKGSRCDIR

unset PKG_PATH || true  #or pkgsrc makefiles will complain

usage()
{
    echo "Usage: pkg_rolling-replace [opts]
        -h         This help
        -B         Pass -B to pkg_chk (only applies with -u)
        -F         Fetch sources (including depends) only, don't build
        -k         Keep running, even on error
        -n         Don't actually do make replace
        -r         Just replace, don't create binary packages
        -s         Replace even if the ABIs are still compatible ("strict")
        -u         Update outdated packages
        -v         Verbose
	-D VAR=VAL Passes given variables and values to make
        -L <path>  Log to path (<path>/pkgdir/pkg)
        -X <pkg>   exclude <pkg> from being rebuilt
        -x <pkg>   exclude <pkg> from outdated check

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
    ${PKG_CHK} -u -q $opt_B | while read line; do
        # duplicate output of pkg_chk to stderr (bypass $(...) or `...`)
        echo "${OPC} $line" 1>&2
	# Look for the first thing that looks like pkg-version rather
	# than category/pkg and remove the version.
        for word in $line; do
            if [ "$(echo $word | egrep '^[^/]+-[0-9][^-/]*$')" ]; then
                echo $word | sed 's/-[0-9][^-]*$//'
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
    for pkgver in $(${PKG_INFO} -e '*'); do
        if ${PKG_INFO} -Bq $pkgver \
                | egrep "^$_flag=[Yy][Ee][Ss]" > /dev/null; then
            echo $pkgver | sed 's/-[0-9][^-]*$//'
        fi
    done
}

# echo dep->pkg edges for all installed packages
depgraph_installed()
{
	${PKG_INFO} -N '*' | ${AWK} '					\
		/^Information for/ {					\
			pkg=$3; sub("-[0-9][^-]*:$", "", pkg);		\
			print pkg" "pkg;				\
			state=1;					\
		}							\
		/^\** PACKAGE MAY NOT BE DELETED \**$/ { state=3; }	\
		/^./ {							\
			if (state == 2) {				\
				dep=$1; sub("-[0-9][^-]*$", "", dep);	\
				print dep" "pkg;			\
			}						\
		}							\
		/^Built using/ {					\
			state=2						\
		}							\
	'
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

report()
{
    for a in $SUCCEEDED; do
        verbose "+ $a"
    done

    for a in $FAILED; do
        verbose "- $a"
    done
}

abort()
{
    echo "*** $1"
    echo "*** Please read the errors listed above, fix the problem,"
    echo "*** then re-run pkg_rolling-replace to continue."
    report
    exit 1
}

error()
{
    if [ -z "$opt_k" ]; then
        abort "$1"
    fi
    echo "*** $1"
}

mark_as_succeeded()
{
    SUCCEEDED=$(uniqify $SUCCEEDED $1)
}

mark_as_failed()
{
    FAILED=$(uniqify $FAILED $1)
}

todo()
{
    if [ -z "$opt_F" ]; then
        verbose "${OPI} Packages to rebuild:"
        verbose "${OPC} MISMATCH_TODO=[$(echo $MISMATCH_TODO)]"  #strip newlines
        verbose "${OPC} REBUILD_TODO=[$(echo $REBUILD_TODO)]"
        verbose "${OPC} UNSAFE_TODO=[$(echo $UNSAFE_TODO)]"
        REPLACE_TODO=$(uniqify $MISMATCH_TODO $REBUILD_TODO $UNSAFE_TODO)
    else
        REPLACE_TODO=$(uniqify $MISMATCH_TODO)
        verbose "${OPI} Packages to fetch:"
        verbose "${OPC} MISMATCH_TODO=[$(echo $MISMATCH_TODO)]"  #strip newlines
    fi
    REPLACE_TODO=$(exclude $REALLYEXCLUDE --from $REPLACE_TODO)
    if [ -n "$FAILED" ]; then
        REPLACE_TODO=$(exclude $FAILED --from $REPLACE_TODO)
    fi
    vsleep 2
}

######################################################################
##
## main()
##

EXCLUDE=
MAKE_VAR="IN_PKG_ROLLING_REPLACE=1"
MAKE_VAR_SEP=" "

args=$(getopt BFhknursvD:x:X:L: $*)
if [ $? -ne 0 ]; then
    opt_h=1
fi
set -- $args
while [ $# -gt 0 ]; do
    case "$1" in
        -B) opt_B=-B ;;
        -F) opt_F=1 ;;
        -h) opt_h=1 ;;
        -k) opt_k=1 ;;
        -n) opt_n=1 ;;
        -r) opt_r=1 ;;
        -s) opt_s=1 ;;
        -u) opt_u=1 ;;
        -v) opt_v=1 ;;
	-D) MAKE_VAR="${MAKE_VAR}${MAKE_VAR_SEP}$2"; MAKE_VAR_SEP=" "; shift ;;
        -x) EXCLUDE="$EXCLUDE $(echo $2 | sed 's/,/ /g')" ; shift ;;
        -X) REALLYEXCLUDE="$REALLYEXCLUDE $(echo $2 | sed 's/,/ /g')" ; shift ;;
        -L) LOGPATH="$2"; shift ;;
        --) shift; break ;;
    esac
    shift
done

if [ -n "$opt_h" ]; then
    usage
fi

if [ -n "$opt_s" ]; then
    UNSAFE_VAR=unsafe_depends_strict
else
    UNSAFE_VAR=unsafe_depends
fi

MAKE="${MAKE}${MAKE_VAR_SEP}${MAKE_VAR}"

SUCCEEDED=""
FAILED=""

MISMATCH_TODO=
if [ -n "$opt_u" -o -n "$opt_F" ]; then
    echo "${OPI} Checking for mismatched installed packages using pkg_chk"
    MISMATCH_TODO=$(check_packages_mismatched)
    echo "${OPI} Excluding the following mismatched packages:"
    echo "${OPC} EXCLUDE=[$EXCLUDE]"
    MISMATCH_TODO=$(exclude $EXCLUDE --from $MISMATCH_TODO)
fi

if [ -z "$opt_F" ]; then
    echo "${OPI} Checking for rebuild-requested installed packages (rebuild=YES)"
    REBUILD_TODO=$(check_packages_w_flag 'rebuild')

    echo "${OPI} Checking for unsafe installed packages (${UNSAFE_VAR}=YES)"
    UNSAFE_TODO=$(check_packages_w_flag ${UNSAFE_VAR})
fi

# DEPGRAPH_INSTALLED is rebuilt each round.  DEPGRAPH_SRC will collect
# edges that we discover using 'make show-depends', but that weren't
# listed as depends by the installed version of a package, and
# DEPENDS_CHECKED lists packages for which we've already done that
# check.
DEPGRAPH_INSTALLED=
DEPGRAPH_SRC=
DEPENDS_CHECKED=

todo

depgraph_built=0

while [ -n "$REPLACE_TODO" ]; do
    fail=

    # don't rebuild depgraph if we continued from new-depends step below
    if [ "$depgraph_built" -eq 0 ]; then
        echo "${OPI} Building dependency graph for installed packages"
        DEPGRAPH_INSTALLED=$(depgraph_installed)
        depgraph_built=1
    fi

    echo "${OPI} Tsorting dependency graph"
    TSORTED=$(echo $DEPGRAPH_INSTALLED $DEPGRAPH_SRC | tsort)
    pkgdir=
    for pkg in $TSORTED; do
        if is_member $pkg $REPLACE_TODO; then
	    pkgdir=$(${PKG_INFO} -Q PKGPATH $pkg)
	    [ -n "$pkgdir" ] || abort "Couldn't extract PKGPATH from installed package $pkg"
            break;
        fi
    done
    # loop should never exit without selecting a package
    [ -n "$pkgdir" ] || abort "pkg_chk reports the following packages need replacing, but they are not installed: $REPLACE_TODO"

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

    # Set PKGNAME_REQD to give underlying make processes a chance to
    # set options derived from the package name.  For example,
    # the appropriate version of Python can be derived from the
    # package name (so, when building py34-foo, use python-3.4,
    # not python-2.7).
    MAKE_SET_VARS="PKGNAME_REQD=${pkg}-*"

    if ! is_member $pkg $DEPENDS_CHECKED; then
	echo "${OPI} Checking if $pkg has new depends..."
	OLD_DEPENDS=$(${PKG_INFO} -Nq $pkg | sed 's/-[0-9][^-]*$//')
	NEW_DEPENDS=
	cd "$PKGSRCDIR/$pkgdir"
	bdeps=$(@SETENV@ ${MAKE_SET_VARS} ${MAKE} show-depends VARNAME=BUILD_DEPENDS)
	rdeps=$(@SETENV@ ${MAKE_SET_VARS} ${MAKE} show-depends)
	for depver in $bdeps $rdeps; do
	    dep=$(echo $depver | sed -e 's/[:[].*$/0/' -e 's/[<>]=/-/' \
		-e 's/-[0-9][^-]*$//')
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

    pkgname=$(${PKG_INFO} -e $pkg)
    if [ -n "$LOGPATH" ]; then
        logdir="$LOGPATH/`dirname $pkgdir`"
        logfile="$logdir/$pkgname"
        @MKDIR@ "$logdir" || abort "mkdir -p '$logdir' failed"
        exec 3>"$logfile"
        tail -f "$logfile" &
        TAILPID=$!
    fi

    # Do make replace, with clean before, and package and clean afterwards.
    fail=
    if [ -d "$PKGSRCDIR/$pkgdir" ]; then
	cd "$PKGSRCDIR/$pkgdir";
    else
        mark_as_failed $pkg
	error "No package directory '$pkgdir' for $pkg."
    fi

    if [ -z "$fail" ]; then
	if [ -z "$opt_F" ]; then
	    echo "${OPI} Replacing $pkgname"
	    cmd="@SETENV@ ${MAKE_SET_VARS} ${MAKE} clean || fail=1"
	    if [ -n "$opt_n" ]; then
		echo "${OPI} Would run: $cmd"
	    else
		if [ -n "$logfile" ]; then
		    eval "$cmd" >&3 2>&3
		else
		    eval "$cmd"
		fi
		if [ -n "$fail" ]; then
                    mark_as_failed $pkg
		    error "'make clean' failed for package $pkg."
		fi
	    fi
	    cmd="@SETENV@ ${MAKE_SET_VARS} ${MAKE} replace || fail=1" # XXX OLDNAME= support? xmlrpc-c -> xmlrpc-c-ss
	else
	    echo "${OPI} Fetching $pkgname"
	    cmd="@SETENV@ ${MAKE_SET_VARS} ${MAKE} fetch depends-fetch || fail=1"
	fi
    fi

    if [ -n "$opt_n" -a -z "$fail" ]; then
	echo "${OPI} Would run: $cmd"
    elif [ -z "$fail" ]; then
        if [ -n "$logfile" ]; then
            eval "$cmd" >&3 2>&3
        else
            eval "$cmd"
        fi
    	if [ -n "$fail" ]; then
            mark_as_failed $pkg
            error "'make replace' failed for package $pkg."
        fi
    fi
    if [ -z "$opt_n" -a -z "$opt_k" -a -z "$opt_F" ]; then
	[ -z "$(${PKG_INFO} -Q unsafe_depends_strict $pkg)" ] || \
	    abort "package $pkg still has unsafe_depends_strict."
	[ -z "$(${PKG_INFO} -Q unsafe_depends $pkg)" ] || \
	    abort "package $pkg still has unsafe_depends."
	[ -z "$(${PKG_INFO} -Q rebuild $pkg)" ] || \
	    abort "package $pkg is still requested to be rebuilt."
    fi
    # If -r not given, make a binary package.
    if [ -z "$opt_r" -a -z "$fail" -a -z "$opt_F" ]; then
	echo "${OPI} Packaging $(${PKG_INFO} -e $pkg)"
	cmd="@SETENV@ ${MAKE_SET_VARS} ${MAKE} package || fail=1"
	if [ -n "$opt_n" -a -z "$fail" ]; then
	    echo "${OPI} Would run: $cmd"
	elif [ -z "$fail" ]; then
            if [ -n "$logfile" ]; then
                eval "$cmd" >&3 2>&3
            else
                eval "$cmd"
            fi
            if [ -n "$fail" ]; then
                mark_as_failed $pkg
                error "'make package' failed for package $pkg."
            fi
	fi
    fi
    # Clean
    if [ -z "$opt_n" -a -z "$fail" -a -z "$opt_F" ]; then
        cmd="@SETENV@ ${MAKE_SET_VARS} ${MAKE} clean || fail=1"
        if [ -n "$logfile" ]; then
            eval "$cmd" >&3 2>&3
        else
            eval "$cmd"
        fi
    	if [ -n "$fail" ]; then
            mark_as_failed $pkg
            error "'make clean' failed for package $pkg."
        fi
    fi

    if [ -z "$fail" ]; then
        mark_as_succeeded $pkg
    fi

    sleep 1

    # remove just-replaced package from all *_TODO lists
    MISMATCH_TODO=$(exclude $pkg --from $MISMATCH_TODO)
    REBUILD_TODO=$(exclude $pkg --from $REBUILD_TODO)
    UNSAFE_TODO=$(exclude $pkg --from $UNSAFE_TODO)

    echo "${OPI} Re-checking for unsafe installed packages (${UNSAFE_VAR}=YES)"
    if [ -n "$opt_n" ]; then
	# With -n, the replace didn't happen, and thus the packages that would
	# have been marked unsafe_depends=YES were not.  Add the set that
	# would have been marked so we can watch what pkg_rolling-replace
	# would have done (approximately).
        UNSAFE_TODO=$(uniqify $UNSAFE_TODO \
            $(who_requires $pkg --in-graph $DEPGRAPH_INSTALLED))
        sleep 1
    else
        UNSAFE_TODO=$(check_packages_w_flag ${UNSAFE_VAR})
    fi

    depgraph_built=0

    todo
    vsleep 2

    if [ -n "$logfile" ]; then
        exec 3>&-
        kill $TAILPID
    fi
done

echo "${OPI} No more packages to replace; done."

report
