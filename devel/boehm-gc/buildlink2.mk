# $NetBSD: buildlink2.mk,v 1.6 2003/05/22 16:46:49 jmmv Exp $
#
# This Makefile fragment is included by packages that use boehm-gc.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BOEHM_GC_BUILDLINK2_MK)
BOEHM_GC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			boehm-gc
BUILDLINK_DEPENDS.boehm-gc?=		boehm-gc>=6.2alpha5
BUILDLINK_PKGSRCDIR.boehm-gc?=		../../devel/boehm-gc

EVAL_PREFIX+=	BUILDLINK_PREFIX.boehm-gc=boehm-gc
BUILDLINK_PREFIX.boehm-gc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.boehm-gc+=	include/gc/*
BUILDLINK_FILES.boehm-gc+=	lib/libgc.*
BUILDLINK_FILES.boehm-gc+=	lib/libleak.*

BUILDLINK_TARGETS+=	boehm-gc-buildlink

boehm-gc-buildlink: _BUILDLINK_USE

.endif	# BOEHM_GC_BUILDLINK2_MK
