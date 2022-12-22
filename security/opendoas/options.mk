# $NetBSD: options.mk,v 1.1 2022/12/22 09:24:38 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendoas

PKG_SUPPORTED_OPTIONS+=	persist
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

##
## Enable credential caching.
##
.if !empty(PKG_OPTIONS:Mpersist)
CONFIGURE_ARGS+=	--with-timestamp
.endif
