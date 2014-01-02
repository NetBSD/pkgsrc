# $NetBSD: options.mk,v 1.2 2014/01/02 06:34:14 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.milkytracker
#PKG_SUPPORTED_OPTIONS=	alsa jack
PKG_SUPPORTED_OPTIONS=	jack
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

#.if !empty(PKG_OPTIONS:Malsa)
#CONFIGURE_ARGS+=	--with-alsa
#.else
CONFIGURE_ARGS+=	--without-alsa
#.endif


.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif
