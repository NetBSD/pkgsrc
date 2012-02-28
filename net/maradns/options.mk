# $NetBSD: options.mk,v 1.1 2012/02/28 21:55:27 cheusov Exp $

PKG_OPTIONS_VAR=                    PKG_OPTIONS.maradns
PKG_SUPPORTED_OPTIONS+=             inet6
PKG_SUGGESTED_OPTIONS+=             inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=                    --ipv6
.endif
