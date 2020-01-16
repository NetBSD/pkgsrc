# $NetBSD: options.mk,v 1.5 2020/01/16 09:49:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rdesktop
PKG_SUPPORTED_OPTIONS+=	inet6 xrandr
PKG_SUGGESTED_OPTIONS+=	inet6 xrandr

.include "../../mk/bsd.options.mk"

###
### Support both IPv6 and IPv4 connections.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if !empty(PKG_OPTIONS:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
.endif
