# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:38:26 jlam Exp $

.if !defined(BOEHM_GC_BUILDLINK2_MK)
BOEHM_GC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		boehm-gc
BUILDLINK_DEPENDS.boehm-gc?=	boehm-gc>=5.3
BUILDLINK_PKGSRCDIR.boehm-gc?=	../../devel/boehm-gc
BUILDLINK_DEPMETHOD.boehm-gc?=	build

EVAL_PREFIX+=				BUILDLINK_PREFIX.boehm-gc=boehm-gc
BUILDLINK_PREFIX.boehm-gc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.boehm-gc=		include/gc.h
BUILDLINK_FILES.boehm-gc+=		include/gc_cpp.h
BUILDLINK_FILES.boehm-gc+=		lib/libgc.a
BUILDLINK_FILES.boehm-gc+=		lib/libleak.a

BUILDLINK_TARGETS+=	boehm-gc-buildlink

boehm-gc-buildlink: _BUILDLINK_USE

.endif	# BOEHM_GC_BUILDLINK2_MK
