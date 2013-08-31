# $NetBSD: options.mk,v 1.2 2013/08/31 22:20:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+= icu

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		icu

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	--with-icu=yes
PLIST.icu=		yes
.else
CONFIGURE_ARGS+=	--with-icu=no
.endif
