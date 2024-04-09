# $NetBSD: hacks.mk,v 1.1 2024/04/09 00:19:29 gutteridge Exp $

.if !defined(LIBREOFFICE_HACKS_MK)
LIBREOFFICE_HACKS_MK=	defined

# For aarch64 on NetBSD we apply -mno-outline-atomics as one way of
# getting around linking issues that otherwise occur with GCC from
# pkgsrc. XXX when -current moves to GCC 12, this should be revisited.
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64*}
CXXFLAGS.NetBSD+=	-mno-outline-atomics
PKG_HACKS+=		gcc-no-outline-atomics
.endif

.endif # LIBREOFFICE_HACKS_MK
