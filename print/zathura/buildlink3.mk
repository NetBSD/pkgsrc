# $NetBSD: buildlink3.mk,v 1.32 2026/03/03 02:34:19 gutteridge Exp $

BUILDLINK_TREE+=	zathura

.if !defined(ZATHURA_BUILDLINK3_MK)
ZATHURA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zathura+=	zathura>=0.2.1
BUILDLINK_ABI_DEPENDS.zathura+=	zathura>=0.5.8nb12
BUILDLINK_PKGSRCDIR.zathura?=	../../print/zathura

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/girara/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # ZATHURA_BUILDLINK3_MK

BUILDLINK_TREE+=	-zathura
