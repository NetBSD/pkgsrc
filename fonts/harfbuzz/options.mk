# $NetBSD: options.mk,v 1.3 2013/10/04 14:34:53 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+= icu
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
