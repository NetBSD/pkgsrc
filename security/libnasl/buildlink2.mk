# $NetBSD: buildlink2.mk,v 1.6 2004/03/26 02:27:52 wiz Exp $
#

.if !defined(LIBNASL_BUILDLINK2_MK)
LIBNASL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libnasl
BUILDLINK_DEPENDS.libnasl?=		libnasl>=2.0.9
BUILDLINK_RECOMMENDED.libnasl?=		libnasl>=2.0.9nb1
BUILDLINK_PKGSRCDIR.libnasl?=		../../security/libnasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.libnasl=libnasl
BUILDLINK_PREFIX.libnasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libnasl+=	include/nessus/nasl.h
BUILDLINK_FILES.libnasl+=	lib/libnasl.*

BUILDLINK_TARGETS+=	libnasl-buildlink

libnasl-buildlink: _BUILDLINK_USE

.endif	# LIBNASL_BUILDLINK2_MK
