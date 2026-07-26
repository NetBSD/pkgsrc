# $NetBSD: options.mk,v 1.1 2026/07/26 20:51:14 thorpej Exp $

#
# nabud package options:
#
# no-pak:
# Disable encrypted PAK file support.
#
# no-ssl:
# Disable SSL/TLS support for remote file access over HTTP.
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.nabud
PKG_SUPPORTED_OPTIONS=	no-pak no-ssl
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mno-pak)
CONFIGURE_ARGS+= --with-pak=no
.endif

.if !empty(PKG_OPTIONS:Mno-ssl)
CONFIGURE_ARGS+= --with-ssl=no
.endif
