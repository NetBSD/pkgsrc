# $NetBSD: buildlink2.mk,v 1.2 2003/01/07 13:20:38 wiz Exp $
#
# This Makefile fragment is included by packages that use gtl.
#

.if !defined(GTL_BUILDLINK2_MK)
GTL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gtl
BUILDLINK_DEPENDS.gtl?=		gtl>=0.3.3
BUILDLINK_PKGSRCDIR.gtl?=	../../devel/gtl

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtl=gtl
BUILDLINK_PREFIX.gtl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtl+=	include/GTL/*
BUILDLINK_FILES.gtl+=	lib/libGTL.*

BUILDLINK_TARGETS+=	gtl-buildlink

gtl-buildlink: _BUILDLINK_USE

.endif	# GTL_BUILDLINK2_MK
