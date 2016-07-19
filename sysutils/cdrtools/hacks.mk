# $NetBSD: hacks.mk,v 1.1 2016/07/19 07:30:27 tron Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${ABI} == "64"
#
# PR pkg/51257: "sysutils/cdrtools" fails to build under Mac OS X 64bit
#               when cwrappers are used
#
USE_CWRAPPERS=	no

.endif
