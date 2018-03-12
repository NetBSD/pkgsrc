# $NetBSD: buildlink3.mk,v 1.41 2018/03/12 11:15:26 wiz Exp $

BUILDLINK_TREE+=	gdl

.if !defined(GDL_BUILDLINK3_MK)
GDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdl+=	gdl>=3.10
BUILDLINK_ABI_DEPENDS.gdl?=	gdl>=3.10.0nb12
BUILDLINK_PKGSRCDIR.gdl?=	../../devel/gdl

.include "../../x11/gtk3/buildlink3.mk"
.endif # GDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdl
