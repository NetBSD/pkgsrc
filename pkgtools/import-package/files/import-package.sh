#! /bin/sh
#
# $NetBSD: import-package.sh,v 1.2 2023/02/12 11:24:46 tnn Exp $
#
# Script designed to make add packages into wip and main pkgsrc easier.
#
# Just cd to the package directory and run import-package
#
# It will automatically create a nice import message based on DESCR
# and PKGNAME, set up the CVS tags correctly and autodetect what CVSROOT
# to use. It also shows you what files will be imported, reminds you
# to run pkglint(1) and asks for confirmation before doing anything.

set -e

[ -n "${MKTEMP}" ] || MKTEMP=mktemp
[ -n "${EDITOR}" ] || EDITOR=vi
CLEANUP=""
DRYRUN="" # "echo dry-run:"

cleanup() {
	if [ -n "${CLEANUP}" ]; then
		rm -f ${CLEANUP}
	fi
}
trap cleanup 0

if [ -z "${MAKE}" ]; then
	if type bmake >/dev/null 2>&1; then
		MAKE=bmake
	else
		MAKE=make
	fi
fi

if [ ! -f "../../mk/bsd.pkg.mk" ]; then
	echo "$0: ../../bsd.pkg.mk not found" 1>&2
	exit 1
fi

stale=no
for cvsdir in $(find "$(pwd)" -type d -name CVS -print); do
	echo "$0: stale CVS state directory found: ${cvsdir}" 1>&2
	stale=yes
done
for gitdir in $(find "$(pwd)" -type d -name .git -print); do
	echo "$0: stale git state directory found: ${gitdir}" 1>&2
	stale=yes
done
for wrkdir in $(find "$(pwd)" -type d -name "work*" -print); do
	echo "$0: stale work directory found: ${wrkdir}" 1>&2
	stale=yes
done
if [ "${stale}" = "yes" ]; then
	exit 1
fi

PACKAGE="$(basename $(pwd))"
CATEGORY="$(basename $(dirname $(pwd)))"
PKGPATH="${CATEGORY}/${PACKAGE}"

if [ "${CATEGORY}" = "wip" ]; then
	SCM=GIT
	if [ ! -d "../.git" ]; then
		echo "$0: git state directory not found in ../.git" 1>&2
		exit 1
	fi
	GIT_BRANCH="$(git rev-parse --abbrev-ref HEAD)"
	if [ "${GIT_BRANCH}" != "master" ]; then
		echo "$0: ${GIT_BRANCH} is not the git master branch" 1>&2
		exit 1
	fi
	if ! git config --get user.name > /dev/null; then
		echo "$0: Please run 'git config --local user.name \"Your name here\"'" 1>&2
		exit 1
	fi
	if ! git config --get user.email > /dev/null; then
		echo "$0: Please run 'git config --local user.email \"you@example.com\"'" 1>&2
		exit 1
	fi
	if git status | grep "Changes to be committed" > /dev/null; then
		echo "$0: You have uncommitted changes staged!" 1>&2
		echo "$0: Check output of 'git status'" 1>&2
		exit 1
	fi
	if ! git fetch; then
	    echo "$0: git fetch failed"
	fi
	if ! git status -u no | egrep "Your branch is (up-to-date|up to date)" > /dev/null; then
		echo "$0: git repository does not appear to be up to date." 1>&2
		echo "$0: You should probably run 'git pull --rebase'" 1>&2
		echo "$0: and 'git push' (if you have unpushed work)" 1>&2
		exit 1
	fi
else
	SCM=CVS
	CVSROOT="$(cat ../CVS/Root | tr A-Z a-z | sed -e 's/.*@//')"
	if [ "${CVSROOT}" != "cvs.netbsd.org:/cvsroot" ]; then
		echo "$0: wrong CVS root: ${CVSROOT}" 1>&2
		exit 1
	fi
fi

MSG="$(${MKTEMP} -t import-package.XXXXXXXX)"
CLEANUP="${MSG}"
echo "Please wait while determining PKGNAME and DESCR_SRC."
PKGNAME="$(${MAKE} show-var VARNAME=PKGNAME)"
DESCR_SRC="$(${MAKE} show-var VARNAME=DESCR_SRC) /dev/null"

DASH70=----------------------------------------------------------------------

echo "${CATEGORY}/${PACKAGE}: import ${PKGNAME}" > ${MSG}
echo "" >> ${MSG}
cat ${DESCR_SRC} >> ${MSG}
echo "${SCM}: ${DASH70}" >> ${MSG}
echo "${SCM}: Please edit the above message to give a brief description" >> ${MSG}
echo "${SCM}: of the package for those who read the *-changes@ list." >> ${MSG}
echo "${SCM}: Did you remember to run pkglint(1) before importing?" >> ${MSG}
echo "${SCM}:" >> ${MSG}
echo "${SCM}: Lines starting with ${SCM}: will be automatically removed." >> ${MSG}
echo "${SCM}:" >> ${MSG}

ADDLIST="$(${MKTEMP} -t import-package-files.XXXXXXXX)"
CLEANUP="${CLEANUP} ${ADDLIST}"
(
	cd ..
	if [ "${SCM}" = "GIT" ]; then
		find ${PACKAGE} -type f -print
	else
		find ${PACKAGE} \( -type d \) -print | sed 's,$,/,'
		find ${PACKAGE} \( -type f \) -print
	fi
) | sed -e '/^\./d' -e '/\/CVS/d' -e '/[^+-_,./a-zA-Z0-9]/d' | sort > ${ADDLIST}
sed "s|^|${SCM}: will add: ${CATEGORY}/|" ${ADDLIST} >> ${MSG}

${EDITOR} ${MSG}

echo "Edited message follows:"
echo ${DASH70}
grep -v "^${SCM}:" < ${MSG}
echo ${DASH70}
echo 	"PKGPATH:	${PKGPATH}"
if [ "${SCM}" = "GIT" ]; then
	echo 	"GIT_BRANCH:	${GIT_BRANCH}"
else
	echo 	"CVSROOT:	${CVSROOT}"
fi

echo ""
printf "y + enter to import, any other text + enter to abort> "
read ANS

if [ "${ANS}" = "y" ]; then
	if [ "${SCM}" = "GIT" ]; then
		(
			cd ..
			cat ${ADDLIST} | xargs -L 100 ${DRYRUN} git add
			${DRYRUN} git commit -m "$(grep -v "^${SCM}:" ${MSG})" ${PACKAGE}
			${DRYRUN} git push
		)
	else
		(
			cd ..
			export CVS_RSH=ssh
			[ -e "${PACKAGE}/CVS" ] || ${DRYRUN} cvs add ${PACKAGE} || exit 1
			grep '/$' ${ADDLIST} | fgrep -vx ${PACKAGE}/ |
			    xargs -L 100 ${DRYRUN} cvs add
			grep -v '/$' ${ADDLIST} | xargs -L 100 ${DRYRUN} cvs add
			${DRYRUN} cvs commit -m "$(grep -v "^${SCM}:" ${MSG})" ${PACKAGE}
		)
	fi
	echo ${DASH70}
	echo "Don't forget to add the package to ${CATEGORY}/Makefile."
	echo "When imported to pkgsrc itself, please update the CHANGES-*"
	echo "file and possibly remove the package from the TODO list."
	echo ""
fi
