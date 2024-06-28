# $NetBSD: options.mk,v 1.8 2024/06/28 08:36:17 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cutter
PKG_SUPPORTED_OPTIONS=	libsoup pdf

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pdf soup

###
### PDF support
###
.if !empty(PKG_OPTIONS:Mpdf)
.include "../../devel/pango/buildlink3.mk"
PLIST.pdf=		yes
.endif

###
### libsoup support
###
.if !empty(PKG_OPTIONS:Mlibsoup)
.  include "../../net/libsoup/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libsoup
PLIST.soup=		yes
.else
CONFIGURE_ARGS+=	--disable-libsoup
.endif
