# $NetBSD: buildlink3.mk,v 1.5 2009/09/08 20:30:25 drochner Exp $

BUILDLINK_TREE+=	gegl

.if !defined(GEGL_BUILDLINK3_MK)
GEGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.0.20
BUILDLINK_ABI_DEPENDS.gegl?=	gegl>=0.1.0nb1
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl

pkgbase := gegl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gegl:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../graphics/babl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # GEGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gegl
