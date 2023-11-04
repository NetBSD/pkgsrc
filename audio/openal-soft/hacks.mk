# $NetBSD: hacks.mk,v 1.1.2.2 2023/11/04 17:27:25 spz Exp $

.if !defined(OPENAL_SOFT_HACKS_MK)
OPENAL_SOFT_HACKS_MK=	defined

# For aarch64, older NetBSD releases will end up pulling in GCC 10 to build
# this, because of the C++20 requirement. We apply -mno-outline-atomics as
# one way of getting around linking issues that otherwise occur.
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64*} && ${OPSYS_VERSION} < 099982
CXXFLAGS.NetBSD+=	-mno-outline-atomics
PKG_HACKS+=		gcc-no-outline-atomics
.endif

.endif # OPENAL_SOFT_HACKS_MK
