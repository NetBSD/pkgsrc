# $NetBSD: options.mk,v 1.1 2013/08/14 01:13:10 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bmp-crossfade
PKG_SUPPORTED_OPTIONS=	libsamplerate

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibsamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif
