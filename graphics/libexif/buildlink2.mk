# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:27 jlam Exp $

.if !defined(LIBEXIF_BUILDLINK2_MK)
LIBEXIF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libexif
BUILDLINK_DEPENDS.libexif?=	libexif>=0.5
BUILDLINK_PKGSRCDIR.libexif?=	../../graphics/libexif

EVAL_PREFIX+=		BUILDLINK_PREFIX.libexif=libexif
BUILDLINK_PREFIX.libexif_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libexif=	include/libexif/*.h
BUILDLINK_FILES.libexif+=	lib/libexif.*

BUILDLINK_TARGETS+=	libexif-buildlink

libexif-buildlink: _BUILDLINK_USE

.endif	# LIBEXIF_BUILDLINK2_MK
