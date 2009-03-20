# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:38 joerg Exp $

BUILDLINK_TREE+=	gdchart

.if !defined(GDCHART_BUILDLINK3_MK)
GDCHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_ABI_DEPENDS.gdchart+=	gdchart>=0.11.5nb2
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart

.include "../../graphics/gd/buildlink3.mk"
.endif # GDCHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdchart
