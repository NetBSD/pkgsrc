# $NetBSD: options.mk,v 1.1 2025/06/30 13:09:36 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bigloo
PKG_SUPPORTED_OPTIONS=	alsa emacs flac mpg123 pulseaudio
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS=	alsa emacs pulseaudio

###
###  Support ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

###
###  Add Full BEE and Emacs support
###
.if !empty(PKG_OPTIONS:Memacs)
CONFIGURE_ARGS+=	--bee=full
CONFIGURE_ARGS+=	--lispdir=${EMACS_LISPPREFIX}
BUILD_TARGET+=	compile-bee
INSTALL_TARGET+=	install-bee
PLIST.emacs=	yes
.include "../../editors/emacs/modules.mk"
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--emacs=no
CONFIGURE_ARGS+=	--bee=partial
.endif


###
###  Support FLAC audio file manipulation
###
.if !empty(PKG_OPTIONS:Mflac)
CONFIGURE_ARGS+=	--enable-flac
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

###
###  Support mpg123
###
.if !empty(PKG_OPTIONS:Mmpg123)
CONFIGURE_ARGS+=	--enable-mpg123
.include "../../audio/mpg123/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mpg123
.endif

###
###  Support pulseaudio
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulseaudio
PLIST.pulseaudio=	yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
