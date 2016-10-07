# $NetBSD: hacks.mk,v 1.5 2016/10/07 13:22:10 joerg Exp $

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" && defined(ABI) && ${ABI} == "64" && \
    ${_USE_CWRAPPERS} == "yes"
#
# PR pkg/51257: "sysutils/cdrtools" fails to build under Mac OS X 64bit
#               when cwrappers are used
#
LDFLAGS+=	-L${PREFIX}/lib -lintl

.endif
