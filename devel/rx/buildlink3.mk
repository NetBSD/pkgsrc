# $NetBSD: buildlink3.mk,v 1.1 2004/02/22 16:48:11 minskim Exp $
#
# This Makefile fragment is included by packages that use rx.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RX_BUILDLINK3_MK:=	${RX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	rx
.endif

.if !empty(RX_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		rx
BUILDLINK_DEPENDS.rx+=		rx>=1.5
BUILDLINK_PKGSRCDIR.rx?=	../../devel/rx

.endif # RX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
