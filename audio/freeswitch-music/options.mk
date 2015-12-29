# $NetBSD: options.mk,v 1.4 2015/12/29 04:54:36 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.freeswitch
PKG_SUPPORTED_OPTIONS=	freeswitch-08k freeswitch-16k freeswitch-32k freeswitch-48k
PKG_SUGGESTED_OPTIONS=	freeswitch-08k freeswitch-16k

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreeswitch-08k)
DISTFILES+=	freeswitch-sounds-music-8000-1.0.8.tar.gz
INSTALLATION_DIRS+= share/freeswitch/sounds/music/8000
SOUND_DIRS+= 8000
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-16k)
DISTFILES+=	freeswitch-sounds-music-16000-1.0.8.tar.gz
SOUND_DIRS+= 16000
INSTALLATION_DIRS+= share/freeswitch/sounds/music/16000
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-32k)
DISTFILES+=	freeswitch-sounds-music-32000-1.0.8.tar.gz
SOUND_DIRS+= 32000
INSTALLATION_DIRS+= share/freeswitch/sounds/music/32000
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-48k)
DISTFILES+=	freeswitch-sounds-music-48000-1.0.8.tar.gz
SOUND_DIRS+= 48000
INSTALLATION_DIRS+= share/freeswitch/sounds/music/48000
.endif

.for opt in ${PKG_SUPPORTED_OPTIONS}
.if !empty(PKG_OPTIONS:M${opt})
PLIST_SUBST+= ${opt}=""
.else
PLIST_SUBST+= ${opt}="@comment "
.endif
.endfor

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}
