# $NetBSD: buildlink2.mk,v 1.5 2003/05/10 19:26:57 jmmv Exp $
#
# This Makefile fragment is included by packages that use boehm-gc.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(BOEHM_GC_BUILDLINK2_MK)
BOEHM_GC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			boehm-gc
BUILDLINK_DEPENDS.boehm-gc?=		boehm-gc>=6.1nb1
BUILDLINK_PKGSRCDIR.boehm-gc?=		../../devel/boehm-gc

EVAL_PREFIX+=	BUILDLINK_PREFIX.boehm-gc=boehm-gc
BUILDLINK_PREFIX.boehm-gc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.boehm-gc+=	include/gc/*
BUILDLINK_FILES.boehm-gc+=	lib/libgc.*
BUILDLINK_FILES.boehm-gc+=	lib/libleak.*

BUILDLINK_TARGETS+=	boehm-gc-buildlink boehm-gc-symlinks

boehm-gc-buildlink: _BUILDLINK_USE

boehm-gc-symlinks:
	@cd ${BUILDLINK_DIR}/include && for hdr in gc/*.h; do \
		${LN} -s $${hdr} .; \
	done

.endif	# BOEHM_GC_BUILDLINK2_MK
