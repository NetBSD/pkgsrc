#!/bin/sh
#
# $NetBSD: pearpc.sh,v 1.1.1.1 2004/06/20 19:33:20 xtraeme Exp $

cd @PREFIX@/share/pearpc && exec ./ppc "$@" @PKG_SYSCONFDIR@/ppccfg.conf
exit 0
