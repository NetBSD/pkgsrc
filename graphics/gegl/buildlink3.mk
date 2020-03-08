# $NetBSD: buildlink3.mk,v 1.41 2020/03/08 16:47:47 wiz Exp $

BUILDLINK_TREE+=	gegl

.if !defined(GEGL_BUILDLINK3_MK)
GEGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.3.0
BUILDLINK_ABI_DEPENDS.gegl?=	gegl>=0.4.22nb1
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl

pkgbase := gegl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gegl:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../graphics/babl/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif # GEGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gegl
