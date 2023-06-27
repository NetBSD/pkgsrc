# $NetBSD: hacks.mk,v 1.6 2023/06/27 20:40:34 bsiegert Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && ${_USE_CWRAPPERS} == "yes"
#
# PR pkg/51257: "sysutils/cdrtools" fails to build under Mac OS X 64bit
#               when cwrappers are used
#
LDFLAGS+=	-L${PREFIX}/lib -lintl

.endif
