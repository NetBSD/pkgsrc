# $NetBSD: options.mk,v 1.1 2014/10/20 10:22:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-anki2
PKG_SUPPORTED_OPTIONS=	lame mplayer portaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlame)
DEPENDS+=	lame-[0-9]*:../../audio/lame
.endif

.if !empty(PKG_OPTIONS:Mmplayer)
DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
DEPENDS+=	portaudio-devel-[0-9]*:../../audio/portaudio-devel
.endif
