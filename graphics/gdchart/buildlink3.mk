# $NetBSD: buildlink3.mk,v 1.1 2004/04/25 04:40:48 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDCHART_BUILDLINK3_MK:=	${GDCHART_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdchart
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdchart}
BUILDLINK_PACKAGES+=	gdchart

.if !empty(GDCHART_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart
.endif	# GDCHART_BUILDLINK3_MK

.include "../../graphics/gd/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
