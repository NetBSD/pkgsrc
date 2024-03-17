# $NetBSD: options.mk,v 1.4 2024/03/17 17:34:05 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ocp
PKG_SUPPORTED_OPTIONS=		alsa
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
CONFIGURE_ARGS+=	--with-alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif
