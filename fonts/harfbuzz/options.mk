# $NetBSD: options.mk,v 1.4 2018/11/23 09:50:55 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+=	icu
PKG_SUGGESTED_OPTIONS=	icu

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icu

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	--with-icu=yes
PLIST.icu=		yes
.else
CONFIGURE_ARGS+=	--with-icu=no
.endif
