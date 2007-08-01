#! /bin/sh
#
# $NetBSD: make.sh,v 1.1 2007/08/01 21:33:40 tnn Exp $
#
# Please read subr.sh for a brief explanation of how this works.

[ -z "$CC" ] && CC=gcc
[ -z "$CPP" ] && CPP="$CC -E"

HEADERS="math.h resolv.h stdlib.h stdint.h sys/select.h"

. ./subr.sh

for hdr in $HEADERS
do
	make_header $hdr
done
