# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/04/11 01:09:14 rh Exp $

.if !defined(RENAISSANCE_BUILDLINK2_MK)
RENAISSANCE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Renaissance
BUILDLINK_DEPENDS.Renaissance?=		Renaissance>=0.7.0
BUILDLINK_PKGSRCDIR.Renaissance?=	../../devel/Renaissance

EVAL_PREFIX+=	BUILDLINK_PREFIX.Renaissance=Renaissance
BUILDLINK_PREFIX.Renaissance_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Renaissance+=	share/GNUstep/System/Library/Headers/Renaissance/*.h

.include "../../x11/gnustep-back/buildlink2.mk"

BUILDLINK_TARGETS+=	Renaissance-buildlink

Renaissance-buildlink: _BUILDLINK_USE

.endif	# RENAISSANCE_BUILDLINK2_MK
