# $NetBSD: buildlink2.mk,v 1.8 2003/08/17 05:01:58 kei Exp $
#
# This Makefile fragment is included by packages that use boehm-gc.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BOEHM_GC_BUILDLINK2_MK)
BOEHM_GC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			boehm-gc
BUILDLINK_DEPENDS.boehm-gc?=		boehm-gc>=6.2nb1
BUILDLINK_PKGSRCDIR.boehm-gc?=		../../devel/boehm-gc

EVAL_PREFIX+=	BUILDLINK_PREFIX.boehm-gc=boehm-gc
BUILDLINK_PREFIX.boehm-gc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.boehm-gc+=	include/gc.h
BUILDLINK_FILES.boehm-gc+=	include/gc_*
BUILDLINK_FILES.boehm-gc+=	include/leak_detector.h
BUILDLINK_FILES.boehm-gc+=	include/gc/*
BUILDLINK_FILES.boehm-gc+=	include/gc/private/*
BUILDLINK_FILES.boehm-gc+=	lib/libgc.*
BUILDLINK_FILES.boehm-gc+=	lib/libleak.*

BUILDLINK_TARGETS+=	boehm-gc-buildlink

boehm-gc-buildlink: _BUILDLINK_USE

.endif	# BOEHM_GC_BUILDLINK2_MK
