# $NetBSD: buildlink3.mk,v 1.4 2006/04/12 10:27:30 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NETATALK_BUILDLINK3_MK:=	${NETATALK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netatalk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGESNnetatalk}
BUILDLINK_PACKAGES+=	netatalk

.if !empty(NETATALK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.netatalk+=	netatalk>=1.6.2
BUILDLINK_ABI_DEPENDS.netatalk+=	netatalk>=1.6.4anb1
BUILDLINK_PKGSRCDIR.netatalk?=	../../net/netatalk1
.endif	# NETATALK_BUILDLINK3_MK

.include "../../devel/rx/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
