# $NetBSD: buildlink2.mk,v 1.1 2003/01/07 06:19:05 rh Exp $
#
# This Makefile fragment is included by packages that use transfig.
#

.if !defined(TRANSFIG_BUILDLINK2_MK)
TRANSFIG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			transfig
BUILDLINK_DEPENDS.transfig?=		transfig>=3.2.4
BUILDLINK_PKGSRCDIR.transfig?=		../../print/transfig

EVAL_PREFIX+=	BUILDLINK_PREFIX.transfig=transfig
BUILDLINK_PREFIX.transfig_DEFAULT=	${X11PREFIX}

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

BUILDLINK_TARGETS+=	transfig-buildlink

transfig-buildlink: _BUILDLINK_USE

.endif	# TRANSFIG_BUILDLINK2_MK
