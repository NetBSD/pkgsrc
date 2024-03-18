# $NetBSD: hacks.mk,v 1.1 2024/03/18 11:42:35 nia Exp $

.ifndef CHECK_HACKS_MK
CHECK_HACKS_MK:=

.include "../../mk/bsd.fast.prefs.mk"

# Needed to get standards-conforming version of unsetenv.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 100500
PKG_HACKS+=		tiger-unix03
CPPFLAGS+=		-D__DARWIN_UNIX03
.endif
.endif
