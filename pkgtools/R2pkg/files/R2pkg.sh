#!/bin/sh
# $NetBSD: R2pkg.sh,v 1.8 2019/10/13 13:26:22 rillig Exp $
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

NAME="R2pkg"
VERS="@VERS@"

R2PKG=${0}

USAGE="${NAME} [-cDehqruVv] [-E editor] [-M maintainer] [package] -- create an R package for pkgsrc"

: ${CRAN_URL:=ftp://cran.r-project.org}
: ${PKGEDITOR:=${EDITOR:=vi}}
: ${TMPDIR:=/tmp}

# Substituted by pkgsrc at pre-configure time.
MAKE=@MAKE@
EDIT=1
LEVEL=0
MAINTAINER_EMAIL=pkgsrc-users@NetBSD.org
PID=$$
QUIET=false
RECURSIVE=false
UPDATE=false
VERBOSE=0

DESCRIPTION=no
DESCRIPTION_CONNECTION=connection

ARGS=""
while getopts cDehqruVvE:M:L:P: f
do
    case ${f} in
	# options without arguments
	c) UPDATE=false; ARGS="${ARGS} -c";;
	D) DESCRIPTION=yes; DESCRIPTION_CONNECTION="'DESCRIPTION'"; ARGS="${ARGS} -D";;
	e) EDIT=0; ARGS="${ARGS} -e";;
	h) echo "${USAGE}"; exit 0;;
	q) QUIET=true; ARGS="${ARGS} -q";;
	r) RECURSIVE=true; ARGS="${ARGS} -r";;
	u) UPDATE=true; ARGS="${ARGS} -u";;
	V) echo "${NAME} v${VERS}"; exit 0;;
	v) VERBOSE=$((${VERBOSE}+1)); ARGS="${ARGS} -v";;
	# options taking arguments
	E) PKGEDITOR=${OPTARG}; ARGS="${ARGS} -E ${PKGEDITOR}";;
	M) MAINTAINER_EMAIL=${OPTARG}; ARGS="${ARGS} -M ${MAINTAINER_EMAIL}";;
	# options for recursion; only for internal use
	L) LEVEL=${OPTARG};;
	P) PID=${OPTARG};;
	# unknown options
        \?) echo "${USAGE}" 1>&2; exit 1;;
    esac
done
shift `expr ${OPTIND} - 1`

# Update ${ARGS} for recursive call
ARGS="${ARGS} -L $((${LEVEL}+1)) -P ${PID}"

if [ ${#} -eq 0 ]; then
    RPKG=$(basename $(pwd) | sed -e 's/^R-//')
elif [ ${#} -eq 1 ]; then
    RPKG=${1}
else
    echo "Error: multiple package names given." 1>&2
    echo "${USAGE}" 1>&2
    exit 1
fi

R_FILE=${TMPDIR}/R2pkg.$$.R

if [ ${UPDATE} = true -a -r Makefile ]; then
    BANNER_MSG="[ ${LEVEL} ] ===> Updating R package R-${RPKG} in $(pwd)"
else
    BANNER_MSG="[ ${LEVEL} ] ===> Creating R package R-${RPKG} in $(pwd)"
fi

PACKAGES_LIST=${TMPDIR}/R2pkg.packages.${PID}
DEPENDENCY_LIST=${TMPDIR}/R2pkg.depends.${PID}

if [ ${QUIET} = true ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER=":"
    ECHO_DONE=":"
    ECHO_FETCH=":"
    ECHO_EXTRACT=":"
    if [ ${LEVEL} -ne 0 ]; then
	ECHO=":"
    fi
elif [ ${VERBOSE} -eq 0 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER="echo"
    ECHO_DONE=":"
    ECHO_FETCH=":"
    ECHO_EXTRACT="echo"
elif [ ${VERBOSE} -eq 1 ]; then
    STDOUT_MAKESUM=">/dev/null"
    STDOUT_EXTRACT=">/dev/null"
    QUIET_CURL="TRUE"
    ECHO_BANNER="echo"
    ECHO_DONE="echo"
    ECHO_FETCH="echo"
    ECHO_EXTRACT="echo"
else
    STDOUT_MAKESUM=""
    STDOUT_EXTRACT=""
    QUIET_CURL="FALSE"
    ECHO_BANNER="echo"
    ECHO_DONE="echo"
    ECHO_FETCH="echo"
    ECHO_EXTRACT="echo"
fi

CRAN_PACKAGES=pub/R/web/packages
RPKG_DESCRIPTION_URL=${CRAN_URL}/${CRAN_PACKAGES}/${RPKG}/DESCRIPTION

check_for_R ()
{
    R_CMD="Rscript --no-save /dev/null"
    eval ${R_CMD}
    if [ ${?} -ne 0 ]; then
	echo "ERROR: math/R package is not installed." 1>&2
	exit 1
    fi
}

check_for_no_recursion ()
{
    touch ${PACKAGES_LIST}
    grep -E -q -e "${RPKG}" ${PACKAGES_LIST} \
	&& echo "ERROR: circular dependency" 1>&2
    echo "${RPKG}" >> ${PACKAGES_LIST}
}

preserve_original_content ()
{
    [ -f Makefile ] && grep -e "CATEGORIES=" Makefile > CATEGORIES
    [ -f Makefile ] && grep -e "COMMENT=" Makefile > COMMENT
    [ -f Makefile ] && grep -e "LICENSE=" Makefile > LICENSE
    [ -f Makefile ] && grep -e "MAINTAINER=" Makefile > MAINTAINER
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
    env LEVEL="${LEVEL}" RPKG="${RPKG}" PACKAGES_LIST="${PACKAGES_LIST}" \
	R2PKG="${R2PKG}" ARGS="${ARGS}" RECURSIVE="${RECURSIVE}" \
	UPDATE="${UPDATE}" DEPENDENCY_LIST="${DEPENDENCY_LIST}" \
	MAINTAINER_EMAIL="${MAINTAINER_EMAIL}" \
	RPKG_DESCRIPTION_URL="${RPKG_DESCRIPTION_URL}" \
	QUIET_CURL="${QUIET_CURL}" \
	Rscript --no-save "@LIBDIR@/R2pkg.R"
    retval=${?}
    if [ ${retval} -ne 0 ]; then
	echo "ERROR: making ${RPKG} package failed." 1>&2
    fi
    return ${retval}
}

edit_Makefile ()
{
    if [ ${EDIT} -ne 0 -a -s Makefile ]; then
	${PKGEDITOR} Makefile
    fi
}

edit_DESCR ()
{
    if [ ${EDIT} -ne 0 -a -s DESCR ]; then
	${PKGEDITOR} DESCR
    fi
}

create_distinfo ()
{
    ${ECHO_FETCH} "==> Fetching R-${RPKG} ..."
    MAKE_CMD="${MAKE} makesum ${STDOUT_MAKESUM}"
    eval ${MAKE_CMD}
    error=${?}
    if [ ${error} -eq 0 ]; then
	MAKE_CMD="${MAKE} makepatchsum ${STDOUT_MAKESUM}"
	eval ${MAKE_CMD}
	error=${?}
    fi
    return ${error}
}

create_buildlink3_mk ()
{
    if [ -f buildlink3.mk.orig ]; then
	PKGVERSION=$(${MAKE} show-var VARNAME=PKGVERSION)
	sed -E -e "/BUILDLINK_API_DEPENDS\./s/[[:digit:].]+$/${PKGVERSION}/" \
	    buildlink3.mk.orig > buildlink3.mk
    fi
}

extract ()
{
    ${ECHO_EXTRACT} "[ ${LEVEL} ] Extracting R-${RPKG} ..."
    MAKE_CMD="env SKIP_DEPENDS=yes ${MAKE} clean extract ${STDOUT_EXTRACT}"
    eval ${MAKE_CMD}
}

check_license ()
{
    rm -f LICENSE
    # echo '===> LICENSE files:'
    if [ -f work/*/LICENSE ]; then
	grep -v "^YEAR: " work/*/LICENSE \
	    | grep -v "^COPYRIGHT HOLDER: " \
	    | grep -v "^ORGANIZATION: " \
	    > LICENSE
	if [ -s LICENSE ]; then
	    # ninka -d LICENSE
	    cp work/*/LICENSE .
	    /bin/echo -n "[ ${LEVEL} ] Current license: "
	    grep LICENSE Makefile
	    echo "[ ${LEVEL} ] Please check it against the following:"
	    cat LICENSE
	else
	    rm LICENSE
	    sed -E -e 's/[[:blank:]]+#[[:blank:]]+\+ file LICENSE[[:blank:]]+.*$//' Makefile > Makefile.$$ \
		&& mv Makefile.$$ Makefile
	    grep -q "file LICENSE" Makefile && echo "[ ${LEVEL} ] 'file LICENSE' in Makefile but no relevant license information"
	fi
    fi
}

check_copying ()
{
    if [ -f work/*/COPYING ]; then
	cp work/*/COPYING .
    fi
    if [ -f work/*/COPYING.lib ]; then
	cp work/*/COPYING.lib .
    fi
}

cleanup_DESCR ()
{
    if [ -f DESCR -a -f DESCR.orig ]; then
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
    if [ -f Makefile -a -f Makefile.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines Makefile.orig Makefile > /dev/null \
	    && mv Makefile.orig Makefile
    elif [ -f Makefile.orig ]; then
	mv Makefile.orig Makefile
    else
	echo "[ ${LEVEL} ] $(pwd): neither Makefile nor Makefile.orig"
    fi
}

cleanup_buildlink3 ()
{
    if [ buildlink3.mk -a -f buildlink3.mk.orig ]; then
	diff --ignore-case --ignore-all-space --ignore-blank-lines buildlink3.mk.orig buildlink3.mk > /dev/null \
	    && mv buildlink3.mk.orig buildlink3.mk
    elif [ -f buildlink3.mk.orig ]; then
	mv buildlink3.mk.orig buildlink3.mk
    fi
}

cleanup_distinfo ()
{
    if [ -f distinfo -a -f distinfo.orig ]; then
	tail +2 distinfo.orig > ${TMPDIR}/distinfo.orig.${PID}
	tail +2 distinfo > ${TMPDIR}/distinfo.${PID}
	cmp -s ${TMPDIR}/distinfo.orig.${PID} ${TMPDIR}/distinfo.${PID} \
	    && mv distinfo.orig distinfo
	rm -f ${TMPDIR}/distinfo.orig.${PID} ${TMPDIR}/distinfo.${PID}
    elif [ -f distinfo.orig ]; then
	mv distinfo.orig distinfo
    fi
}

cleanup_misc_files ()
{
    [ "${DESCRIPTION}" = "yes" ] || rm -f DESCRIPTION
    rm -f ${R_FILE}
    rm -f CATEGORIES
    rm -f COMMENT
    rm -f MAINTAINER
    rm -f USE_LANGUAGES
    rm -f USE_TOOLS
    rm -f DEPENDS
    rm -f BUILDLINK3.MK
    [ ${LEVEL} -eq 0 ] && rm -f ${PACKAGES_LIST}
    [ ${LEVEL} -eq 0 ] && rm -f ${DEPENDENCY_LIST}
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
    if [ ${QUIET} = false -a ${LEVEL} -eq 0 ]; then
	cat << EOF

Please do not forget the following:
- check DESCR and edit as necessary.
- check Makefile:
  o verify the COMMENT.
  o verify the LICENSE.
  o verify the DEPENDS, especially the categories.
EOF
	[ -f buildlink3.mk ] && echo "- check buildlink3.mk"

	[ "${DESCRIPTION}" = "yes" ] && echo "- remove DESCRIPTION."
	if [ ${RECURSIVE} = true ]; then
	    cat << EOF

Recursive packages may have been created in ../../wip; please do the following:
- edit each Makefile as follows (in addition to following the notes above):
  o move recursively created packages to the appropriate category.
  o fix the category in Makefile.
  o fix the category of any dependencies.
  o remove any extraneous dependencies.
EOF
	    if [ -s ${DEPENDENCY_LIST} ]; then
		tsort ${DEPENDENCY_LIST} > depends
		echo "- It may be useful to test these packages in the following order:"
		awk 'BEGIN{printf(" ")} {printf(" R-%s",$0)}' depends && echo
	    fi
	fi
    fi
}

${ECHO_BANNER} "${BANNER_MSG} ..."
check_for_R
check_for_no_recursion
preserve_original_content
make_package
error=${?}
if [ ${error} -eq 0 ]; then
    edit_Makefile
    error=${?}; [ ${error} -eq 0 ] || exit ${error}
    edit_DESCR
    error=${?}; [ ${error} -eq 0 ] || exit ${error}
    create_distinfo
    create_buildlink3_mk
    extract
    check_license
    check_copying
fi
messages
cleanup
if [ ${error} -eq 0 ]; then
    ${ECHO_DONE} "${BANNER_MSG}: completed successfully"
else
    ${ECHO_DONE} "${BANNER_MSG}: FAILED"
fi
exit ${error}
