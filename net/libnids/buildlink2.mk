# $NetBSD: buildlink2.mk,v 1.1 2003/10/10 08:44:44 cube Exp $

.if !defined(LIBNIDS_BUILDLINK2_MK)
LIBNIDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libnids
BUILDLINK_DEPENDS.libnids?=	libnids>=1.17
BUILDLINK_PKGSRCDIR.libnids?=	../../net/libnids

BUILDLINK_DEPMETHOD.libnids?=	build

EVAL_PREFIX+=			BUILDLINK_PREFIX.libnids=libnids
BUILDLINK_PREFIX.libnids_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnids=	include/nids.h
BUILDLINK_FILES.libnids+=	lib/libnids.a

BUILDLINK_TARGETS+=	libnids-buildlink

libnids-buildlink: _BUILDLINK_USE

.endif	# LIBNIDS_BUILDLINK2_MK
