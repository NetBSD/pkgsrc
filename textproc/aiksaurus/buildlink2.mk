# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/02 15:05:39 kei Exp $

.if !defined(AIKSAURUS_BUILDLINK2_MK)
AIKSAURUS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Aiksaurus
BUILDLINK_DEPENDS.Aiksaurus?=		Aiksaurus>=0.15
BUILDLINK_PKGSRCDIR.Aiksaurus?=		../../textproc/aiksaurus

EVAL_PREFIX+=	BUILDLINK_PREFIX.Aiksaurus=Aiksaurus
BUILDLINK_PREFIX.Aiksaurus_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Aiksaurus+=	include/Aiksaurus.h
BUILDLINK_FILES.Aiksaurus+=	include/AiksaurusC.h
BUILDLINK_FILES.Aiksaurus+=	lib/libAiksaurus.*

BUILDLINK_TARGETS+=	Aiksaurus-buildlink

Aiksaurus-buildlink: _BUILDLINK_USE

.endif	# AIKSAURUS_BUILDLINK2_MK
