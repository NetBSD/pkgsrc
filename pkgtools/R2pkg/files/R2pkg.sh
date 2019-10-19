#!/bin/sh
# $NetBSD: R2pkg.sh,v 1.12 2019/10/19 18:43:51 rillig Exp $
#
# Copyright (c) 2014,2015,2016,2017,2018,2019
#	Brook Milligan.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the author nor the names of any contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
#
# Create an R package in the current directory
#

set -u

name="R2pkg"
vers="@VERS@"

r2pkg=$0

usage="$name [-cDehqruVv] [-E editor] [-M maintainer] [package] -- create an R package for pkgsrc"

: "${CRAN_URL:=ftp://cran.r-project.org}"
: "${PKGEDITOR:=${EDITOR:=vi}}"
: "${TMPDIR:=/tmp}"

# Substituted by pkgsrc at pre-configure time.
make=@MAKE@
level=0
maintainer_email="pkgsrc-users@NetBSD.org"
pid=$$
quiet=false
recursive=false
update=false
use_editor=yes
verbose=0

keep_description=no

args=""
while getopts cDehqruVvE:M:L:P: arg
do
    case $arg in
	# options without arguments
	c) args="$args $arg"; update=false;;
	D) args="$args $arg"; keep_description=yes;;
	e) args="$args $arg"; use_editor=no;;
	h) echo "$usage"; exit 0;;
	q) args="$args $arg"; quiet=true;;
	r) args="$args $arg"; recursive=true;;
	u) args="$args $arg"; update=true;;
	V) echo "$name v$vers"; exit 0;;
	v) args="$args $arg"; verbose=$((verbose + 1));;
	# options taking arguments
	E) args="$args $arg $OPTARG"; PKGEDITOR=$OPTARG;;
	M) args="$args $arg $OPTARG"; maintainer_email=$OPTARG;;
	# options for recursion; only for internal use
	L) level=$((OPTARG + 0));;
	P) pid=$((OPTARG + 0));;
	# unknown options
	\?) echo "$usage" 1>&2; exit 1;;
    esac
done
shift $((OPTIND - 1))

# Update $args for recursive call
args="$args -L $((level + 1)) -P $pid"

if [ ${#} -eq 0 ]; then
    rpkg=$(basename "$(pwd)" | sed -e 's/^R-//')
elif [ ${#} -eq 1 ]; then
    rpkg=$1
else
    echo "Error: multiple package names given." 1>&2
    echo "$usage" 1>&2
    exit 1
fi

if [ $update = true ] && [ -r Makefile ]; then
    banner_msg="[ $level ] ===> Updating R package R-$rpkg in $(pwd)"
else
    banner_msg="[ $level ] ===> Creating R package R-$rpkg in $(pwd)"
fi

packages_list=$TMPDIR/R2pkg.packages.$pid
dependency_list=$TMPDIR/R2pkg.depends.$pid

echo_verbose0() { echo "$@"; }
echo_verbose1() { :; }
show_verbose2() { "$@" >/dev/null; }
quiet_curl="TRUE"
if [ $quiet = true ]; then
    echo_verbose0() { :; }
elif [ $verbose -eq 1 ]; then
    echo_verbose1() { echo "$@"; }
elif [ $verbose -gt 1 ]; then
    echo_verbose1() { echo "$@"; }
    show_verbose2() { "$@"; }
    quiet_curl="FALSE"
fi

rpkg_description_url=$CRAN_URL/pub/R/web/packages/$rpkg/DESCRIPTION

exists ()
{
    case "$#,$*" in (1,*\**) return 1;; esac
    return 0
}

check_for_R ()
{
    Rscript --no-save /dev/null && return
    echo "ERROR: math/R package is not installed." 1>&2
    exit 1
}

check_for_no_recursion ()
{
    touch "$packages_list"
    grep -E -q -e "$rpkg" "$packages_list" \
	&& echo "ERROR: circular dependency" 1>&2
    echo "$rpkg" >> "$packages_list"
}

preserve_original_content ()
{
    [ -f Makefile ] && grep -e "CATEGORIES=" Makefile > CATEGORIES
    [ -f Makefile ] && grep -e "COMMENT=" Makefile > COMMENT
    [ -f Makefile ] && grep -e "USE_LANGUAGES" Makefile > USE_LANGUAGES
    [ -f Makefile ] && grep -e "USE_TOOLS" Makefile > USE_TOOLS
    [ -f Makefile ] && grep -e "DEPENDS" Makefile > DEPENDS
    [ -f Makefile ] && grep -e "buildlink3.mk" Makefile > BUILDLINK3.MK

    [ -f DESCR ]    && mv DESCR DESCR.orig
    [ -f Makefile ] && mv Makefile Makefile.orig
    [ -f buildlink3.mk ] && mv buildlink3.mk buildlink3.mk.orig
    [ -f distinfo ] && mv distinfo distinfo.orig
}

make_package ()
{
    env LEVEL="$level" rpkg="$rpkg" PACKAGES_LIST="$packages_list" \
	R2PKG="$r2pkg" ARGS="$args" RECURSIVE="$recursive" \
	UPDATE="$update" DEPENDENCY_LIST="$dependency_list" \
	MAINTAINER_EMAIL="$maintainer_email" \
	RPKG_DESCRIPTION_URL="$rpkg_description_url" \
	QUIET_CURL="$quiet_curl" \
	LC_ALL="C" \
	Rscript --no-save -e "source('@LIBDIR@/R2pkg.R'); main()"
    retval=${?}
    if [ $retval -ne 0 ]; then
	echo "ERROR: making $rpkg package failed." 1>&2
    fi
    return $retval
}

edit_Makefile ()
{
    if [ $use_editor = yes ] && [ -s Makefile ]; then
	$PKGEDITOR Makefile
    fi
}

edit_DESCR ()
{
    if [ $use_editor = yes ] && [ -s DESCR ]; then
	$PKGEDITOR DESCR
    fi
}

create_distinfo ()
{
    echo_verbose1 "==> Fetching R-$rpkg ..."
    show_verbose2 "$make" "makesum" || return $?
    show_verbose2 "$make" "makepatchsum" || return $?
    return 0
}

create_buildlink3_mk ()
{
    if [ -f buildlink3.mk.orig ]; then
	PKGVERSION=$($make show-var VARNAME=PKGVERSION)
	sed -E -e "/BUILDLINK_API_DEPENDS\./s/[[:digit:].]+$/$PKGVERSION/" \
	    buildlink3.mk.orig > buildlink3.mk
    fi
}

extract ()
{
    echo_verbose0 "[ $level ] Extracting R-$rpkg ..."
    show_verbose2 env SKIP_DEPENDS=yes "$make" clean extract
}

check_license ()
{
    rm -f LICENSE
    # echo '===> LICENSE files:'
    if exists work/*/LICENSE; then
	grep -v "^YEAR: " work/*/LICENSE \
	    | grep -v "^COPYRIGHT HOLDER: " \
	    | grep -v "^ORGANIZATION: " \
	    > LICENSE
	if [ -s LICENSE ]; then
	    # ninka -d LICENSE
	    cp work/*/LICENSE .
	    printf '%s' "[ $level ] Current license: "
	    grep LICENSE Makefile
	    echo "[ $level ] Please check it against the following:"
	    cat LICENSE
	else
	    rm LICENSE
	    sed -E -e 's/[[:blank:]]+#[[:blank:]]+\+ file LICENSE[[:blank:]]+.*$//' Makefile > Makefile.$pid \
		&& mv Makefile.$pid Makefile
	    grep -q "file LICENSE" Makefile && echo "[ $level ] 'file LICENSE' in Makefile but no relevant license information"
	fi
    fi
}

check_copying ()
{
    exists work/*/COPYING && cp work/*/COPYING .
    exists work/*/COPYING.lib && cp work/*/COPYING.lib .
}

cleanup_DESCR ()
{
    if [ -f DESCR ] && [ -f DESCR.orig ]; then
	if diff --ignore-case --ignore-all-space --ignore-blank-lines DESCR.orig DESCR > /dev/null; then
	    mv DESCR.orig DESCR
	else
	    mv DESCR DESCR.new
	    mv DESCR.orig DESCR
	fi
    elif [ -f DESCR.orig ]; then
	mv DESCR.orig DESCR
    fi
}

cleanup_Makefile ()
{
    if [ -f Makefile ] && [ -f Makefile.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines Makefile.orig Makefile > /dev/null \
	    && mv Makefile.orig Makefile
    elif [ -f Makefile.orig ]; then
	mv Makefile.orig Makefile
    fi
}

cleanup_buildlink3 ()
{
    if [ -f buildlink3.mk ] && [ -f buildlink3.mk.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines buildlink3.mk.orig buildlink3.mk > /dev/null \
	    && mv buildlink3.mk.orig buildlink3.mk
    elif [ -f buildlink3.mk.orig ]; then
	mv buildlink3.mk.orig buildlink3.mk
    fi
}

cleanup_distinfo ()
{
    if [ -f distinfo ] && [ -f distinfo.orig ]; then
	tail +2 distinfo.orig > $TMPDIR/distinfo.orig.$pid
	tail +2 distinfo > $TMPDIR/distinfo.$pid
	cmp -s $TMPDIR/distinfo.orig.$pid $TMPDIR/distinfo.$pid \
	    && mv distinfo.orig distinfo
	rm -f $TMPDIR/distinfo.orig.$pid $TMPDIR/distinfo.$pid
    elif [ -f distinfo.orig ]; then
	mv distinfo.orig distinfo
    fi
}

cleanup_misc_files ()
{
    [ "$keep_description" = "yes" ] || rm -f DESCRIPTION
    rm -f CATEGORIES
    rm -f COMMENT
    rm -f USE_LANGUAGES
    rm -f USE_TOOLS
    rm -f DEPENDS
    rm -f BUILDLINK3.MK
    [ $level -eq 0 ] && rm -f "$packages_list"
    [ $level -eq 0 ] && rm -f "$dependency_list"
}

cleanup ()
{
    cleanup_DESCR
    cleanup_Makefile
    cleanup_buildlink3
    cleanup_distinfo
    cleanup_misc_files
}

messages ()
{
    if [ $quiet = false ] && [ $level -eq 0 ]; then
	cat << EOF

Please do not forget the following:
- check DESCR and edit as necessary.
- check Makefile:
  o verify the COMMENT.
  o verify the LICENSE.
  o verify the DEPENDS, especially the categories.
EOF
	[ -f buildlink3.mk ] && echo "- check buildlink3.mk"

	[ "$keep_description" = "yes" ] && echo "- remove DESCRIPTION."
	if [ $recursive = true ]; then
	    cat << EOF

Recursive packages may have been created in ../../wip; please do the following:
- edit each Makefile as follows (in addition to following the notes above):
  o move recursively created packages to the appropriate category.
  o fix the category in Makefile.
  o fix the category of any dependencies.
  o remove any extraneous dependencies.
EOF
	    if [ -s "$dependency_list" ]; then
		tsort "$dependency_list" > depends
		echo "- It may be useful to test these packages in the following order:"
		awk 'BEGIN{printf(" ")} {printf(" R-%s",$0)}' depends && echo
	    fi
	fi
    fi
}

echo_verbose0 "$banner_msg ..."
check_for_R
check_for_no_recursion
preserve_original_content
make_package
error=${?}
if [ $error -eq 0 ]; then
    edit_Makefile
    error=${?}; [ $error -eq 0 ] || exit $error
    edit_DESCR
    error=${?}; [ $error -eq 0 ] || exit $error
    create_distinfo
    create_buildlink3_mk
    extract
    check_license
    check_copying
fi
messages
cleanup
if [ $error -eq 0 ]; then
    echo_verbose1 "$banner_msg: completed successfully"
else
    echo_verbose1 "$banner_msg: FAILED"
fi
exit $error
