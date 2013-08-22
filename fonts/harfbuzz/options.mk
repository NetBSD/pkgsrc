# $NetBSD: options.mk,v 1.1 2013/08/22 15:34:32 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.harfbuzz
PKG_SUPPORTED_OPTIONS+= icu

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Micu)
.include "../../textproc/icu/buildlink3.mk"
CONFIGURE_ARGS+=	--with-icu=yes
PKGCONFIG_OVERRIDE+=	src/harfbuzz-icu.pc.in
PLIST.icu=	yes
.else
CONFIGURE_ARGS+=	--with-icu=no
.endif
