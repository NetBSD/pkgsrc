# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:17:56 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NETATALK_BUILDLINK3_MK:=	${NETATALK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	netatalk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGESNnetatalk}
BUILDLINK_PACKAGES+=	netatalk

.if !empty(NETATALK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.netatalk+=	netatalk>=1.6.2
BUILDLINK_RECOMMENDED.netatalk+=	netatalk>=1.6.2nb1
BUILDLINK_PKGSRCDIR.netatalk?=	../../net/netatalk
.endif	# NETATALK_BUILDLINK3_MK

.include "../../devel/rx/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
