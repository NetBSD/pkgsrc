# $NetBSD: options.mk,v 1.4 2022/01/03 12:36:53 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	dane guile lzo
PKG_SUGGESTED_OPTIONS=	lzo

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdane)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST_SRC+=		PLIST.dane
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif

.if !empty(PKG_OPTIONS:Mguile)
.include "../../lang/guile22/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-guile
PLIST_SRC+=		PLIST.guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if !empty(PKG_OPTIONS:Mlzo)
.include "../../archivers/lzo/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lzo
.else
CONFIGURE_ARGS+=	--disable-lzo
.endif
