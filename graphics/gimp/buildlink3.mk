# $NetBSD: buildlink3.mk,v 1.26 2008/09/30 19:55:03 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIMP_BUILDLINK3_MK:=	${GIMP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gimp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngimp}
BUILDLINK_PACKAGES+=	gimp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gimp

.if !empty(GIMP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.4.0
BUILDLINK_ABI_DEPENDS.gimp+=	gimp>=2.4.4
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp
.endif	# GIMP_BUILDLINK3_MK

pkgbase := gimp
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gimp:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gimp:Mgnome)
.include "../../www/libgtkhtml/buildlink3.mk"
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
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
