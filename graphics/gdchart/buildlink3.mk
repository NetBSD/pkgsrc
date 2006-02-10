# $NetBSD: buildlink3.mk,v 1.4 2006/02/10 12:17:05 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDCHART_BUILDLINK3_MK:=	${GDCHART_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdchart
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdchart}
BUILDLINK_PACKAGES+=	gdchart

.if !empty(GDCHART_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_RECOMMENDED.gdchart+=	gdchart>=0.11.5nb1
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart
.endif	# GDCHART_BUILDLINK3_MK

.include "../../graphics/gd/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
