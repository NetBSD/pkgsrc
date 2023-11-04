# $NetBSD: hacks.mk,v 1.1.2.2 2023/11/04 13:26:56 spz Exp $

.if !defined(LIBATOMIC_HACKS_MK)
LIBATOMIC_HACKS_MK=	defined

# For aarch64, GCC expects a recent version of itself that accepts
# -mno-outline-atomics.
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64*} && ${OPSYS_VERSION} < 099982
GCC_REQD+=	10
PKG_HACKS+=	gcc-no-outline-atomics-required
.endif

.endif # LIBATOMIC_HACKS_MK
