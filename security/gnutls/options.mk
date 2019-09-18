# $NetBSD: options.mk,v 1.1 2019/09/18 15:27:05 ng0 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnutls
PKG_SUPPORTED_OPTIONS=	dane
PLIST_VARS+=		dane

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdane)
.include "../../net/unbound/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libdane
PLIST.dane=		yes
.else
CONFIGURE_ARGS+=	--disable-libdane
.endif
