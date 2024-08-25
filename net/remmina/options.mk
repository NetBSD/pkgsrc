# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:08 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.remmina

# XXX needs avahi with gtk3
PKG_SUPPORTED_OPTIONS=		avahi libappindicator
PKG_SUGGESTED_OPTIONS=		libappindicator

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CMAKE_CONFIGURE_ARGS+=	-DWITH_AVAHI=ON
.include "../../net/avahi/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_AVAHI=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibappindicator)
.include "../../devel/libappindicator/buildlink3.mk"
.endif
