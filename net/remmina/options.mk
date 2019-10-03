# $NetBSD: options.mk,v 1.2 2019/10/03 00:07:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.remmina

# XXX needs avahi with gtk3
PKG_SUPPORTED_OPTIONS=		avahi libappindicator
PKG_SUGGESTED_OPTIONS=		libappindicator

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mavahi)
CMAKE_ARGS+=	-DWITH_AVAHI=ON
.include "../../net/avahi/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_AVAHI=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibappindicator)
.include "../../devel/libappindicator/buildlink3.mk"
.endif
