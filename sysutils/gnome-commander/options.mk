# $NetBSD: options.mk,v 1.2 2009/09/16 10:59:55 drochner Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-commander
PKG_SUPPORTED_OPTIONS=	python exif id3 chm gsf pdf
PKG_SUGGESTED_OPTIONS=	python exif id3 chm gsf pdf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/application.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.python
.endif

.if !empty(PKG_OPTIONS:Mexif)
.include "../../graphics/exiv2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mid3)
.include "../../audio/taglib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mchm)
.include "../../devel/chmlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgsf)
.include "../../devel/libgsf/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpdf)
# API change: getPDFVersion() -> getPDF{Major,Minor}Version()
BUILDLINK_API_DEPENDS.poppler+= poppler>=0.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.endif
