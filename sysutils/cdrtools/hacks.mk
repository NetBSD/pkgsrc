# $NetBSD: hacks.mk,v 1.4 2016/07/21 19:38:31 tron Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && defined(ABI) && ${ABI} == "64" && \
    ${USE_CWRAPPERS:tl} != "no"
#
# PR pkg/51257: "sysutils/cdrtools" fails to build under Mac OS X 64bit
#               when cwrappers are used
#
LDFLAGS+=	-L${PREFIX}/lib -lintl

.endif
