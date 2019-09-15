# $NetBSD: options.mk,v 1.1 2019/09/15 12:59:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.remmina
PKG_SUPPORTED_OPTIONS=		avahi libappindicator
PKG_SUGGESTED_OPTIONS=		avahi libappindicator

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
