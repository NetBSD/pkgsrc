# $NetBSD: buildlink2.mk,v 1.4 2003/06/23 07:49:39 jlam Exp $
#
# This Makefile fragment is included by packages that use icu.

.if !defined(ICU_BUILDLINK2_MK)
ICU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		icu
BUILDLINK_DEPENDS.icu?=		icu>=2.6
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

EVAL_PREFIX+=			BUILDLINK_PREFIX.icu=icu
BUILDLINK_PREFIX.icu_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.icu+=	include/layout/*
BUILDLINK_FILES.icu+=	include/unicode/*
BUILDLINK_FILES.icu+=	lib/libicudata.*
BUILDLINK_FILES.icu+=	lib/libicui18n.*
BUILDLINK_FILES.icu+=	lib/libicuio.*
BUILDLINK_FILES.icu+=	lib/libicule.*
BUILDLINK_FILES.icu+=	lib/libiculx.*
BUILDLINK_FILES.icu+=	lib/libicutoolutil.*
BUILDLINK_FILES.icu+=	lib/libicuuc.*

BUILDLINK_TARGETS+=	icu-buildlink

icu-buildlink: _BUILDLINK_USE

.endif	# ICU_BUILDLINK2_MK
