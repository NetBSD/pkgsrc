# $NetBSD: buildlink2.mk,v 1.5 2004/04/15 00:49:29 wiz Exp $

.if !defined(AIKSAURUS_BUILDLINK2_MK)
AIKSAURUS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			aiksaurus
BUILDLINK_DEPENDS.aiksaurus?=		aiksaurus>=1.0.1
BUILDLINK_PKGSRCDIR.aiksaurus?=		../../textproc/aiksaurus

EVAL_PREFIX+=	BUILDLINK_PREFIX.aiksaurus=aiksaurus
BUILDLINK_PREFIX.aiksaurus_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aiksaurus+=	include/Aiksaurus/Aiksaurus.h
BUILDLINK_FILES.aiksaurus+=	include/Aiksaurus/AiksaurusC.h
BUILDLINK_FILES.aiksaurus+=	lib/libAiksaurus-1.0.*
BUILDLINK_FILES.aiksaurus+=	lib/libAiksaurus.*

BUILDLINK_TARGETS+=	aiksaurus-buildlink

aiksaurus-buildlink: _BUILDLINK_USE

.endif	# AIKSAURUS_BUILDLINK2_MK
