# $NetBSD: options.mk,v 1.6 2023/02/15 07:40:52 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	dane

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdane)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST_SRC+=		PLIST.dane
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif
