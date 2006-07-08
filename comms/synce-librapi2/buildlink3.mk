# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SYNCE_LIBRAPI2_BUILDLINK3_MK:=	${SYNCE_LIBRAPI2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	synce-librapi2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsynce-librapi2}
BUILDLINK_PACKAGES+=	synce-librapi2
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}synce-librapi2

.if !empty(SYNCE_LIBRAPI2_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.synce-librapi2+=	synce-librapi2>=0.9.1
BUILDLINK_PKGSRCDIR.synce-librapi2?=	../../comms/synce-librapi2
.endif	# SYNCE_LIBRAPI2_BUILDLINK3_MK

.include "../../comms/synce-libsynce/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
