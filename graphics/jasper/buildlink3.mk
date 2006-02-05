# $NetBSD: buildlink3.mk,v 1.5 2006/02/05 23:09:34 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
JASPER_BUILDLINK3_MK:=	${JASPER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	jasper
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Njasper}
BUILDLINK_PACKAGES+=	jasper

.if !empty(JASPER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.jasper+=	jasper>=1.600.0
BUILDLINK_RECOMMENDED.jasper+=	jasper>=1.701.0nb2
BUILDLINK_PKGSRCDIR.jasper?=	../../graphics/jasper
.endif	# JASPER_BUILDLINK3_MK

.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
