# $NetBSD: buildlink3.mk,v 1.43 2018/11/12 03:51:09 ryoon Exp $

BUILDLINK_TREE+=	gdl

.if !defined(GDL_BUILDLINK3_MK)
GDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdl+=	gdl>=3.10
BUILDLINK_ABI_DEPENDS.gdl?=	gdl>=3.10.0nb15
BUILDLINK_PKGSRCDIR.gdl?=	../../devel/gdl

.include "../../x11/gtk3/buildlink3.mk"
.endif # GDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdl
