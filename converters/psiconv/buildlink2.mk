# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:01 jlam Exp $

.if !defined(PSICONV_BUILDLINK2_MK)
PSICONV_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		psiconv
BUILDLINK_DEPENDS.psiconv?=	psiconv>=0.6.1
BUILDLINK_PKGSRCDIR.psiconv?=	../../converters/psiconv

EVAL_PREFIX+=				BUILDLINK_PREFIX.psiconv=psiconv
BUILDLINK_PREFIX.psiconv_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.psiconv=	include/psiconv/*
BUILDLINK_FILES.psiconv+=	lib/libpsiconv.*

BUILDLINK_TARGETS+=	psiconv-buildlink

psiconv-buildlink: _BUILDLINK_USE

.endif	# PSICONV_BUILDLINK2_MK
