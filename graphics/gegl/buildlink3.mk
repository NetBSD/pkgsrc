# $NetBSD: buildlink3.mk,v 1.29 2014/05/05 00:47:56 ryoon Exp $

BUILDLINK_TREE+=	gegl

.if !defined(GEGL_BUILDLINK3_MK)
GEGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.2.0
BUILDLINK_ABI_DEPENDS.gegl+=	gegl>=0.2.0nb17
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl

pkgbase := gegl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gegl:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../graphics/babl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GEGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gegl
