# $NetBSD: buildlink3.mk,v 1.20 2020/03/08 16:48:05 wiz Exp $

BUILDLINK_TREE+=	ghostscript-gpl

.if !defined(GHOSTSCRIPT_GPL_BUILDLINK3_MK)
GHOSTSCRIPT_GPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghostscript-gpl+=	ghostscript-gpl>=8.63nb1
BUILDLINK_ABI_DEPENDS.ghostscript-gpl+=	ghostscript-gpl>=9.06nb32
BUILDLINK_PKGSRCDIR.ghostscript-gpl?=	../../print/ghostscript-gpl

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := ghostscript-gpl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ghostscript-gpl:Mcups)
.include "../../print/cups-base/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript-gpl:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript-gpl:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif
.endif # GHOSTSCRIPT_GPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghostscript-gpl
