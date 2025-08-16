# $NetBSD: options.mk,v 1.1 2025/08/16 01:11:39 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups-browsed
PKG_SUPPORTED_OPTIONS=	avahi
PKG_SUGGESTED_OPTIONS=	avahi

.include "../../mk/bsd.options.mk"

#
# Avahi support
#
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif
