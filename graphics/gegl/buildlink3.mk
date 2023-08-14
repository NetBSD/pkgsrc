# $NetBSD: buildlink3.mk,v 1.48 2023/08/14 05:24:32 wiz Exp $

BUILDLINK_TREE+=	gegl

.if !defined(GEGL_BUILDLINK3_MK)
GEGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.3.0
BUILDLINK_ABI_DEPENDS.gegl+=	gegl>=0.4.46nb1
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl

.include "../../graphics/babl/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif # GEGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gegl
