#!/bin/sh
#
# $NetBSD: maildirmake.sh,v 1.3 2002/01/02 19:26:02 jlam Exp $
#
# Wrapper to execute maildirmake from amongst any installed maildirmake
# executable.

maildirmake=
for file in @LOCALBASE@/bin/maildirmake.* @LOCALBASE@/bin/*.maildirmake
do
	if [ -x ${file} ]
	then
		maildirmake=${file}
	fi
done

if [ -z "${maildirmake}" ]
then
	@ECHO@ "$0: can't find a valid maildirmake executable"
	exit 1
fi

exec ${maildirmake} $*
