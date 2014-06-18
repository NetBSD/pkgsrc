# $NetBSD: buildlink3.mk,v 1.6 2014/06/18 09:26:11 wiz Exp $

BUILDLINK_TREE+=	ghostscript-agpl

.if !defined(GHOSTSCRIPT_AGPL_BUILDLINK3_MK)
GHOSTSCRIPT_AGPL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ghostscript-agpl+=	ghostscript-agpl>=8.63nb1
BUILDLINK_ABI_DEPENDS.ghostscript-agpl+=	ghostscript-agpl>=9.10nb1
BUILDLINK_PKGSRCDIR.ghostscript-agpl?=		../../print/ghostscript-agpl

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := ghostscript-agpl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.ghostscript-agpl:Mcups)
.include "../../print/cups15/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript-agpl:Mfontconfig)
.include "../../fonts/fontconfig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.ghostscript-agpl:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif
.endif # GHOSTSCRIPT_AGPL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ghostscript-agpl
