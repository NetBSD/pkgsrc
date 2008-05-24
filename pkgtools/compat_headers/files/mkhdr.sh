#! /bin/sh
#
# $NetBSD: mkhdr.sh,v 1.1.1.1 2008/05/24 03:35:42 tnn Exp $
#

[ "${CC}" = "" ] && CC="cc"
CPP="${CC} -E -"

# Prints the full absolute pathname to the file that is included by doing
# #include <file.h>.
real_header() {
	echo "#include <$1>" | $CPP - 2> /dev/null |\
		awk -F\" '/^\# 1 "\// {if(!done){print $2;done=1;}}'
}

real_hdr="`real_header $1`"
[ "${real_hdr}" = "" ] && real_hdr="stdio.h"
${CPP} | sed -e "s,@real_header@,${real_hdr}," -e 's/^#.*//' -e 's/^@/#/' | grep -v '^$'
