# $NetBSD: buildlink2.mk,v 1.2 2003/10/28 16:57:00 cube Exp $

.if !defined(LIBNIDS_BUILDLINK2_MK)
LIBNIDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libnids
BUILDLINK_DEPENDS.libnids?=	libnids>=1.18
BUILDLINK_PKGSRCDIR.libnids?=	../../net/libnids

BUILDLINK_DEPMETHOD.libnids?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.libnids=libnids
BUILDLINK_PREFIX.libnids_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnids=	include/nids.h
BUILDLINK_FILES.libnids+=	lib/libnids.a

BUILDLINK_TARGETS+=	libnids-buildlink

libnids-buildlink: _BUILDLINK_USE

.endif	# LIBNIDS_BUILDLINK2_MK
