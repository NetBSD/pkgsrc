#!@SH@
# $NetBSD: thunderbird.sh,v 1.1.1.1 2003/12/04 05:24:42 grant Exp $

LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:@PREFIX@/lib/thunderbird-@PLATFORM@:@PREFIX@/lib"
export LD_LIBRARY_PATH

exec @PREFIX@/lib/thunderbird-@PLATFORM@/thunderbird "$@"
