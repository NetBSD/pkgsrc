# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:42 jlam Exp $

.if !defined(CHASEN_BUILDLINK2_MK)
CHASEN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		chasen
BUILDLINK_DEPENDS.chasen?=	chasen>=2.0
BUILDLINK_PKGSRCDIR.chasen?=	../../textproc/chasen

EVAL_PREFIX+=	BUILDLINK_PREFIX.chasen=chasen
BUILDLINK_PREFIX.chasen_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.chasen=		include/chasen.h
BUILDLINK_FILES.chasen+=	lib/libchasen.*

BUILDLINK_TARGETS+=	chasen-buildlink

chasen-buildlink: _BUILDLINK_USE

.endif	# CHASEN_BUILDLINK2_MK
