# $NetBSD: buildlink3.mk,v 1.29 2025/08/30 22:46:13 wiz Exp $

BUILDLINK_TREE+=	zathura

.if !defined(ZATHURA_BUILDLINK3_MK)
ZATHURA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zathura+=	zathura>=0.2.1
BUILDLINK_ABI_DEPENDS.zathura+=	zathura>=0.5.8nb9
BUILDLINK_PKGSRCDIR.zathura?=	../../print/zathura

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/girara/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif # ZATHURA_BUILDLINK3_MK

BUILDLINK_TREE+=	-zathura
