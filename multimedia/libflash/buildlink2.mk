# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/26 13:34:45 jmmv Exp $

.if !defined(LIBFLASH_BUILDLINK2_MK)
LIBFLASH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libflash
BUILDLINK_DEPENDS.libflash?=	libflash>=0.4.10nb4
BUILDLINK_PKGSRCDIR.libflash?=	../../multimedia/libflash

EVAL_PREFIX+=	BUILDLINK_PREFIX.libflash=libflash
BUILDLINK_PREFIX.libflash_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libflash+=	include/flash/*.h
BUILDLINK_FILES.libflash+=	lib/libflash.*

BUILDLINK_CPPFLAGS.libflash=	-I${BUILDLINK_PREFIX.libflash}/include/flash
CPPFLAGS+=	${BUILDLINK_CPPFLAGS.libflash}

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	libflash-buildlink

libflash-buildlink: _BUILDLINK_USE

.endif	# LIBFLASH_BUILDLINK2_MK
