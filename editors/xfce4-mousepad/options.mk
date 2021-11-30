# $NetBSD: options.mk,v 1.1 2021/11/30 00:45:38 gutteridge Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mousepad
PKG_SUPPORTED_OPTIONS=	gspell
PKG_SUGGESTED_OPTIONS=	gspell

.include "../../mk/bsd.options.mk"

PLIST_VARS=	gspell

.if !empty(PKG_OPTIONS:Mgspell)
.include "../../textproc/gspell/buildlink3.mk"
PLIST.gspell=	yes
CONFIGURE_ARGS+=	--enable-plugin-gspell
.else
CONFIGURE_ARGS+=	--disable-plugin-gspell
.endif
