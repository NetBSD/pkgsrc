# $NetBSD: options.mk,v 1.1 2008/11/29 21:47:32 spz Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.bind95
PKG_SUPPORTED_OPTIONS=  bind-xml-statistics-server
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# use the statistics server in bind95 and later? It'll need libxml2
.if !empty(PKG_OPTIONS:Mbind-xml-statistics-server)
.include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=--with-libxml2=yes
.else
CONFIGURE_ARGS+=--with-libxml2=no
.endif

