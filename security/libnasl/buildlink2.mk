# $NetBSD: buildlink2.mk,v 1.1 2002/10/25 21:11:27 wiz Exp $
#

.if !defined(LIBNASL_BUILDLINK2_MK)
LIBNASL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libnasl
BUILDLINK_DEPENDS.libnasl?=		libnasl>=1.2.6
BUILDLINK_PKGSRCDIR.libnasl?=		../../security/libnasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.libnasl=libnasl
BUILDLINK_PREFIX.libnasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnasl+=	include/nessus/nasl.h
BUILDLINK_FILES.libnasl+=	lib/libnasl.*

BUILDLINK_TARGETS+=	libnasl-buildlink

libnasl-buildlink: _BUILDLINK_USE

.endif	# LIBNASL_BUILDLINK2_MK
