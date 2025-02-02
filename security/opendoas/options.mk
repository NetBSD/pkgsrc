# $NetBSD: options.mk,v 1.2 2025/02/02 10:59:47 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendoas

PKG_SUPPORTED_OPTIONS+=	persist
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

##
## Enable credential caching.
##
.if !empty(PKG_OPTIONS:Mpersist)
CONFIGURE_ENV+=		OS=linux
CONFIGURE_ARGS+=	--with-timestamp
.endif
