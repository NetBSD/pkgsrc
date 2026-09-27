# $NetBSD: buildlink3.mk,v 1.36 2026/09/27 11:38:20 tnn Exp $

BUILDLINK_TREE+=	zathura

.if !defined(ZATHURA_BUILDLINK3_MK)
ZATHURA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zathura+=	zathura>=2026.02.22
BUILDLINK_ABI_DEPENDS.zathura?=	zathura>=2026.02.22nb3
BUILDLINK_PKGSRCDIR.zathura?=	../../print/zathura

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/girara/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # ZATHURA_BUILDLINK3_MK

BUILDLINK_TREE+=	-zathura
