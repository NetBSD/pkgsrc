# $NetBSD: hacks.mk,v 1.1 2021/09/30 11:39:27 nia Exp $

.if !defined(ZIP_HACKS_MK)
ZIP_HACKS_MK=	# defined

.if !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
PKG_HACKS+=	disable-opt

# This was added in 2003 to work around a compiler bug...
# is it still even required?
CFLAGS+=	-O0
.endif

.endif	# ZIP_HACKS_MK
