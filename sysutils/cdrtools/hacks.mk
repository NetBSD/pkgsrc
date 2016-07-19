# $NetBSD: hacks.mk,v 1.2 2016/07/19 07:33:24 tron Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && defined(ABI) && ${ABI} == "64"
#
# PR pkg/51257: "sysutils/cdrtools" fails to build under Mac OS X 64bit
#               when cwrappers are used
#
USE_CWRAPPERS=	no

.endif
