# $NetBSD: hacks.mk,v 1.4 2023/12/07 00:42:47 gutteridge Exp $

.if !defined(EXIV2_HACKS_MK)
EXIV2_HACKS_MK=	defined

# For aarch64, older NetBSD releases will end up pulling in GCC 10 to
# build this, because of the C++ <filesystem> requirement. We apply
# -mno-outline-atomics as one way of getting around linking issues that
# otherwise occur.
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64*} && ${OPSYS_VERSION} < 099982
CXXFLAGS.NetBSD+=	-mno-outline-atomics
PKG_HACKS+=		gcc-no-outline-atomics
.endif

.endif # EXIV2_HACKS_MK
