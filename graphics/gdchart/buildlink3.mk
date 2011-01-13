# $NetBSD: buildlink3.mk,v 1.13 2011/01/13 13:36:52 wiz Exp $

BUILDLINK_TREE+=	gdchart

.if !defined(GDCHART_BUILDLINK3_MK)
GDCHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_ABI_DEPENDS.gdchart+=	gdchart>=0.11.5nb6
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart

.include "../../graphics/gd/buildlink3.mk"
.endif # GDCHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdchart
