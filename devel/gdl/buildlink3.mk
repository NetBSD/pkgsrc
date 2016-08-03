# $NetBSD: buildlink3.mk,v 1.37 2016/08/03 10:22:09 adam Exp $

BUILDLINK_TREE+=	gdl

.if !defined(GDL_BUILDLINK3_MK)
GDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdl+=	gdl>=3.10
BUILDLINK_ABI_DEPENDS.gdl?=	gdl>=3.10.0nb8
BUILDLINK_PKGSRCDIR.gdl?=	../../devel/gdl

.include "../../x11/gtk3/buildlink3.mk"
.endif # GDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdl
