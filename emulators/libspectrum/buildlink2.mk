# $NetBSD: buildlink2.mk,v 1.2 2004/02/13 13:36:43 adam Exp $

.if !defined(LIBSPECTRUM_BUILDLINK2_MK)
LIBSPECTRUM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libspectrum
BUILDLINK_DEPENDS.libspectrum?=		libspectrum>=0.2.1
BUILDLINK_PKGSRCDIR.libspectrum?=	../../emulators/libspectrum

EVAL_PREFIX+=	BUILDLINK_PREFIX.libspectrum=libspectrum
BUILDLINK_PREFIX.libspectrum_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libspectrum=	include/libspectrum.h
BUILDLINK_FILES.libspectrum+=	lib/libspectrum.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

BUILDLINK_TARGETS+=	libspectrum-buildlink

libspectrum-buildlink: _BUILDLINK_USE

.endif	# LIBSPECTRUM_BUILDLINK2_MK
