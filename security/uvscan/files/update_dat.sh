#!/bin/sh

UVSCANDIR="@UVSCANDIR@"
DAT_SITE="ftp://ftp.nai.com/pub/datfiles/english/"
DAT_FILES="@DATFILES@"
TMPDIR="${TMPDIR:-/tmp}/$$"

AWK="@AWK@"
BASENAME="@BASENAME@"
CP="@CP@"
ECHO="@ECHO@"
GREP="@GREP@"
GTAR="@GTAR@"
MKDIR="@MKDIR@"
MV="@MV@"
RM="@RM@"                               
SED="@SED@"                             

progname=`${BASENAME} $0`

while getopts vf: arg; do
	case $arg in
	v)	verbose=1 ;;
	f)	dat_tar="${OPTARG}" ;;
	esac
done

${MKDIR} ${TMPDIR}

if [ -n "$dat_tar" ]; then
	if ! (${GTAR} -x -C ${TMPDIR} -f $dat_tar readme.txt >/dev/null); then
		${ECHO} "$progname: unable to extract readme.txt"
		${RM} -rf ${TMPDIR}
		exit 1  
	fi
else
	# Fetch the ReadMe file to read the latest version of the DAT files.
	if ! (cd ${TMPDIR}; ftp ${DAT_SITE}readme.txt >/dev/null); then
		${ECHO} "$progname: unable to fetch ${DAT_SITE}readme.txt"
		${RM} -rf ${TMPDIR}
		exit 1  
	fi
fi

curver=`${AWK} '/DAT Version/ { print $4; exit }' ${TMPDIR}/readme.txt | ${SED} -e 's/^.*\([0-9][0-9][0-9][0-9]\).*$/\1/'`
oldver=`${AWK} '/DAT Version/ { print $4; exit }' ${UVSCANDIR}/readme.txt | ${SED} -e 's/^.*\([0-9][0-9][0-9][0-9]\).*$/\1/'`

if [ $curver -le $oldver ]; then
	if [ -z "$verbose" ]; then
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
			exit 1  
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
