#!/bin/sh
#
# $NetBSD: dhid.sh,v 1.1 1999/08/04 14:04:36 jlam Exp $

DHID=@PREFIX@/libexec/dhid
if [ -f ${DHID} ]; then
	@ECHO@ -n " dhid"
	${DHID}
fi
