# $NetBSD: buildlink2.mk,v 1.2 2004/01/17 15:32:33 recht Exp $
#

.if !defined(LIBCDIO_BUILDLINK2_MK)
LIBCDIO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libcdio
BUILDLINK_DEPENDS.libcdio?=		libcdio>=0.65
BUILDLINK_PKGSRCDIR.libcdio?=		../../misc/libcdio

EVAL_PREFIX+=	BUILDLINK_PREFIX.libcdio=libcdio
BUILDLINK_PREFIX.libcdio_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libcdio+=	include/cdio/*.h
BUILDLINK_FILES.libcdio+=	lib/libcdio.*
BUILDLINK_FILES.libcdio+=	lib/libiso9660.*

BUILDLINK_TARGETS+=	libcdio-buildlink

libcdio-buildlink: _BUILDLINK_USE

.endif	# LIBCDIO_BUILDLINK2_MK
