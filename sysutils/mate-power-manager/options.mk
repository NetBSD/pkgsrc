# $NetBSD: options.mk,v 1.2 2020/05/31 23:44:49 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-power-manager
PKG_SUPPORTED_OPTIONS=	keyring
PKG_SUGGESTED_OPTIONS=	keyring

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkeyring)
.include "../../security/libgnome-keyring/buildlink3.mk"
CONFIGURE_ARGS+=	--with-keyring
.else
CONFIGURE_ARGS+=	--without-keyring
.endif
