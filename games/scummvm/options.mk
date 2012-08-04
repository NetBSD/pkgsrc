# $NetBSD: options.mk,v 1.8 2012/08/04 14:45:34 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.scummvm
PKG_SUPPORTED_OPTIONS=	fluidsynth

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
.endif
