# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:53 jlam Exp $

.if !defined(LIBCRACK_BUILDLINK2_MK)
LIBCRACK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libcrack
BUILDLINK_DEPENDS.libcrack?=	libcrack>=2.7
BUILDLINK_PKGSRCDIR.libcrack?=	../../security/libcrack

EVAL_PREFIX+=	BUILDLINK_PREFIX.libcrack=libcrack
BUILDLINK_PREFIX.libcrack_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libcrack=	include/cracklib/*
BUILDLINK_FILES.libcrack+=	lib/libcrack.*

BUILDLINK_TARGETS+=	libcrack-buildlink

libcrack-buildlink: _BUILDLINK_USE

.endif	# LIBCRACK_BUILDLINK2_MK
