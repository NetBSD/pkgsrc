# $NetBSD: buildlink2.mk,v 1.1 2003/08/05 17:18:20 wiz Exp $

.if !defined(LIBIDEA_BUILDLINK2_MK)
LIBIDEA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libidea
BUILDLINK_DEPENDS.libidea?=	libidea>=0.8.2
BUILDLINK_PKGSRCDIR.libidea?=	../../security/libidea

EVAL_PREFIX+=	BUILDLINK_PREFIX.libidea=libidea
BUILDLINK_PREFIX.libidea_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.libidea=	include/idea.h
BUILDLINK_FILES.libidea+=	lib/libidea.*

BUILDLINK_TARGETS+=	libidea-buildlink

libidea-buildlink: _BUILDLINK_USE

.endif	# LIBIDEA_BUILDLINK2_MK
