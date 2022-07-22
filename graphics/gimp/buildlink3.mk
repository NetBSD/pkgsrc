# $NetBSD: buildlink3.mk,v 1.79 2022/07/22 20:19:58 wiz Exp $

BUILDLINK_TREE+=	gimp

.if !defined(GIMP_BUILDLINK3_MK)
GIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.4.0<2.99
BUILDLINK_ABI_DEPENDS.gimp+=	gimp>=2.10.30nb3
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp

pkgbase := gimp
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gimp:Maalib}
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gimp:Mmng}
.include "../../graphics/mng/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp
