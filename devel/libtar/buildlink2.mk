# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:15 jlam Exp $

.if !defined(LIBTAR_BUILDLINK2_MK)
LIBTAR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libtar
BUILDLINK_DEPENDS.libtar?=	libtar>=1.2.5
BUILDLINK_PKGSRCDIR.libtar?=	../../devel/libtar

EVAL_PREFIX+=		BUILDLINK_PREFIX.libtar=libtar
BUILDLINK_PREFIX.libtar_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libtar=		include/libtar*
BUILDLINK_FILES.libtar+=	lib/libtar.*

BUILDLINK_TARGETS+=	libtar-buildlink

libtar-buildlink: _BUILDLINK_USE

.endif	# LIBTAR_BUILDLINK2_MK
