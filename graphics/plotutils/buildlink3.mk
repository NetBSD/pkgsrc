# $NetBSD: buildlink3.mk,v 1.1 2004/02/21 14:46:50 minskim Exp $
#
# This Makefile fragment is included by packages that use plotutils.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PLOTUTILS_BUILDLINK3_MK:=	${PLOTUTILS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	plotutils
.endif

.if !empty(PLOTUTILS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			plotutils
BUILDLINK_DEPENDS.plotutils+=		plotutils>=2.4.1nb2
BUILDLINK_PKGSRCDIR.plotutils?=		../../graphics/plotutils

.include "../../graphics/png/buildlink3.mk"

.endif # PLOTUTILS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
