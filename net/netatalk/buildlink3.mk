# $NetBSD: buildlink3.mk,v 1.1 2004/02/22 16:51:23 minskim Exp $
#
# This Makefile fragment is included by packages that use netatalk.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NETATALK_BUILDLINK3_MK:=	${NETATALK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netatalk
.endif

.if !empty(NETATALK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			netatalk
BUILDLINK_DEPENDS.netatalk+=		netatalk>=1.6.2
BUILDLINK_PKGSRCDIR.netatalk?=		../../net/netatalk

.include "../../devel/rx/buildlink3.mk"

.endif # NETATALK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
