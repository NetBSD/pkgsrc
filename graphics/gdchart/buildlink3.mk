# $NetBSD: buildlink3.mk,v 1.6 2006/04/17 13:46:05 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDCHART_BUILDLINK3_MK:=	${GDCHART_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdchart
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdchart}
BUILDLINK_PACKAGES+=	gdchart

.if !empty(GDCHART_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_ABI_DEPENDS.gdchart+=	gdchart>=0.11.5nb2
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart
.endif	# GDCHART_BUILDLINK3_MK

.include "../../graphics/gd/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
