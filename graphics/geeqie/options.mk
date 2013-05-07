# $NetBSD: options.mk,v 1.1 2013/05/07 11:08:40 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=	libchamplain
PKG_SUGGESTED_OPTIONS=	libchamplain

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
CONFIGURE_ARGS+=	--enable-gps
.include "../../geography/libchamplain04/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gps
.endif
