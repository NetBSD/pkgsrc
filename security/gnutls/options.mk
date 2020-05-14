# $NetBSD: options.mk,v 1.3 2020/05/14 14:30:02 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	dane guile

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
