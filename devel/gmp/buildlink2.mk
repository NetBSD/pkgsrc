# $NetBSD: buildlink2.mk,v 1.1 2002/08/27 06:23:53 jlam Exp $

.if !defined(GMP_BUILDLINK2_MK)
GMP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gmp
BUILDLINK_DEPENDS.gmp?=		gmp>=4.1
BUILDLINK_PKGSRCDIR.gmp?=	../../devel/gmp

EVAL_PREFIX+=			BUILDLINK_PREFIX.gmp=gmp
BUILDLINK_PREFIX.gmp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gmp=		include/gmp.h
BUILDLINK_FILES.gmp+=		lib/libgmp.*

BUILDLINK_TARGETS+=	gmp-buildlink

gmp-buildlink: _BUILDLINK_USE

.endif	# GMP_BUILDLINK2_MK
