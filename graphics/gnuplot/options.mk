# $NetBSD: options.mk,v 1.3 2011/03/10 09:44:10 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuplot
PKG_SUPPORTED_OPTIONS=	gd pdf x11
PKG_SUGGESTED_OPTIONS=	gd x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11

.if !empty(PKG_OPTIONS:Mgd)
.include "../../graphics/gd/buildlink3.mk"
.endif

# PDF output is also provided by cairo
.if !empty(PKG_OPTIONS:Mpdf)
CONFIGURE_ARGS+=	--with-pdf
.include "../../print/pdflib-lite/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
.include "../../x11/libXaw/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
