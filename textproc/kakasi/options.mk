# $NetBSD: options.mk,v 1.1 2014/06/06 12:09:47 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kakasi
PKG_SUPPORTED_OPTIONS=	utf8
PKG_SUGGESTED_OPTIONS=	utf8

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mutf8)
CONFIGURE_ARGS+=	--enable-utf8
.include "../../converters/libiconv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif
