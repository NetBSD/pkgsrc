# $NetBSD: buildlink2.mk,v 1.1 2002/09/11 18:40:12 jlam Exp $

.if !defined(IJS_BUILDLINK2_MK)
IJS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		ijs
BUILDLINK_DEPENDS.ijs?=		ijs>=0.34
BUILDLINK_PKGSRCDIR.ijs?=	../../print/ijs

EVAL_PREFIX+=	BUILDLINK_PREFIX.ijs=ijs
BUILDLINK_PREFIX.ijs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ijs=	include/ijs/*
BUILDLINK_FILES.ijs+=	lib/libijs.*

BUILDLINK_TARGETS+=	ijs-buildlink

ijs-buildlink: _BUILDLINK_USE

.endif	# IJS_BUILDLINK2_MK
