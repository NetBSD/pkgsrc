# $NetBSD: options.mk,v 1.1 2025/03/03 02:35:31 scole Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tk-tkimg
PKG_SUPPORTED_OPTIONS=	debug ghostscript x11
PKG_SUGGESTED_OPTIONS+=	ghostscript x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols
.else
CONFIGURE_ARGS+=	--disable-symbols
.endif

.if !empty(PKG_OPTIONS:Mghostscript)
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

# This package was previously named tk-tkimg
.if defined(PKG_OPTIONS.tk-tkimg)
PKG_LEGACY_OPTIONS+=	${PKG_OPTIONS.tk-tkimg}
PKG_OPTIONS_DEPRECATED_WARNINGS+=	\
	"Deprecated variable PKG_OPTIONS.tk-tkimg used, use "${PKG_OPTIONS_VAR:Q}" instead."
.endif
