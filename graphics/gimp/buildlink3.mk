# $NetBSD: buildlink3.mk,v 1.43 2012/09/15 10:04:52 obache Exp $

BUILDLINK_TREE+=	gimp

.if !defined(GIMP_BUILDLINK3_MK)
GIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.4.0
BUILDLINK_ABI_DEPENDS.gimp+=	gimp>=2.8.2nb2
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp

pkgbase := gimp
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gimp:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gimp:Mmng)
.include "../../graphics/mng/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gimp:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp
