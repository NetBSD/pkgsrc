# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/13 15:03:42 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYNCE_LIBRAPI2_BUILDLINK3_MK:=	${SYNCE_LIBRAPI2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	synce-librapi2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynce-librapi2}
BUILDLINK_PACKAGES+=	synce-librapi2

.if !empty(SYNCE_LIBRAPI2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.synce-librapi2+=	synce-librapi2>=0.9.1
BUILDLINK_PKGSRCDIR.synce-librapi2?=	../../comms/synce-librapi2
.endif	# SYNCE_LIBRAPI2_BUILDLINK3_MK

.include "../../comms/synce-libsynce/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
