# $NetBSD: options.mk,v 1.1 2019/11/10 20:11:30 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tk-tkimg
PKG_SUPPORTED_OPTIONS=	debug x11
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-symbols
.else
CONFIGURE_ARGS+=	--disable-symbols
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libX11/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x --x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
.else
CONFIGURE_ARGS+=	--without-x
.endif
