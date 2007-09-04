#!/bin/sh
#
# $NetBSD: update_dat.sh,v 1.5 2007/09/04 19:43:15 jlam Exp $

UVSCANDIR="@UVSCANDIR@"
DAT_SITE="http://download.nai.com/products/datfiles/4.x/nai/"
DAT_FILES="@DATFILES@"
TMPDIR="${TMPDIR:-/tmp}/$$"

AWK="@AWK@"
BASENAME="@BASENAME@"
CP="@CP@"
ECHO="@ECHO@"
GTAR="@GTAR@"
MKDIR="@MKDIR@"
MV="@MV@"
RM="@RM@"                               
SED="@SED@"                             

progname=`${BASENAME} $0`

while getopts vhf: arg; do
	case $arg in
	v)	verbose=1 ;;
	f)	dat_tar="${OPTARG}" ;;
	h)
		echo "Usage: $0 [-h] [-f <datfile>] [-v]"
		exit 0
		;;
	esac
done

(${ECHO} writetest > ${UVSCANDIR}/writetest) >/dev/null 2>&1
if [ $? != 0 ]; then
	echo ${progname}: no write access to ${UVSCANDIR} -- update aborted.
	exit 1
else
	${RM} -f ${UVSCANDIR}/writetest
fi

${MKDIR} ${TMPDIR}

if [ -n "$dat_tar" ]; then
	if ! (${GTAR} -x -C ${TMPDIR} -f $dat_tar pkgdesc.ini >/dev/null); then
		${ECHO} "$progname: unable to extract pkgdesc.ini"
		${RM} -rf ${TMPDIR}
		exit 2  
	fi
	curver=`${AWK} -F= '/Version/ { print $2; exit }' ${TMPDIR}/pkgdesc.ini | ${SED} -e 's/^.*\([0-9][0-9][0-9][0-9]\).*$/\1/'`
else
	# Fetch the update.ini file to read the latest version of the DAT files.
	if ! (cd ${TMPDIR}; ftp ${DAT_SITE}update.ini >/dev/null); then
		${ECHO} "$progname: unable to fetch ${DAT_SITE}update.ini"
		${RM} -rf ${TMPDIR}
		exit 3  
	fi
	curver=`${AWK} -F= '/DATVersion/ { print $2; exit }' ${TMPDIR}/update.ini | ${SED} -e 's/^.*\([0-9][0-9][0-9][0-9]\).*$/\1/'`
fi

if [ -e ${UVSCANDIR}/pkgdesc.ini ]; then
	oldver=`${AWK} -F= '/Version/ { print $2; exit }' ${UVSCANDIR}/pkgdesc.ini | ${SED} -e 's/^.*\([0-9][0-9][0-9][0-9]\).*$/\1/'`
else
	oldver=0
fi

if [ $curver -le $oldver ]; then
	if [ -n "$verbose" ]; then
		${ECHO} "$progname: VirusScan DAT files are current ($oldver)"
	fi
else
	if [ -z "$dat_tar" ]; then
		dat_tar=${DAT_SITE}dat-$curver.tar
		if (cd ${TMPDIR}; ftp $dat_tar >/dev/null); then
			dat_tar=${TMPDIR}/dat-$curver.tar
		else
			${ECHO} "$progname: unable to fetch $dat_tar"
			${RM} -rf ${TMPDIR}
			exit 4  
		fi
	fi

	${GTAR} -x -C ${TMPDIR} -f $dat_tar

	# Backup old dat-* tar files.
	if [ "`${ECHO} ${UVSCANDIR}/*.tar`" != "${UVSCANDIR}/*.tar" ]; then
		for file in ${UVSCANDIR}/*.tar; do
			${MV} -f $file $file.old
		done
	fi

	# Backup old DAT files.
	for file in ${DAT_FILES}; do
		file=${UVSCANDIR}/$file
		if [ -f $file ]; then
			${MV} -f $file $file.bak
		fi
	done

	# Copy new DAT files into place.
	for file in ${DAT_FILES}; do
		${CP} -f ${TMPDIR}/$file ${UVSCANDIR}/$file
	done
	${CP} -f $dat_tar ${UVSCANDIR}
	${RM} -f ${UVSCANDIR}/*.old
	${ECHO} `date` Successfully updated VirusScan DAT files to $curver.
fi

${RM} -rf ${TMPDIR}
exit 0
