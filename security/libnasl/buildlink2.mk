# $NetBSD: buildlink2.mk,v 1.5 2003/11/08 07:40:17 xtraeme Exp $
#

.if !defined(LIBNASL_BUILDLINK2_MK)
LIBNASL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libnasl
BUILDLINK_DEPENDS.libnasl?=		libnasl>=2.0.9
BUILDLINK_PKGSRCDIR.libnasl?=		../../security/libnasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.libnasl=libnasl
BUILDLINK_PREFIX.libnasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnasl+=	include/nessus/nasl.h
BUILDLINK_FILES.libnasl+=	lib/libnasl.*

BUILDLINK_TARGETS+=	libnasl-buildlink

libnasl-buildlink: _BUILDLINK_USE

.endif	# LIBNASL_BUILDLINK2_MK
