# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:14:59 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
UNICON_IM_BUILDLINK3_MK:=	${UNICON_IM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	unicon-im
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nunicon-im}
BUILDLINK_PACKAGES+=	unicon-im

.if !empty(UNICON_IM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.unicon-im+=	unicon-im>=1.2nb2
BUILDLINK_RECOMMENDED.unicon-im+=	unicon-im>=1.2nb3
BUILDLINK_PKGSRCDIR.unicon-im?=	../../inputmethod/unicon-im
.endif	# UNICON_IM_BUILDLINK3_MK

.include "../../devel/pth/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
