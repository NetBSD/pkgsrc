# $NetBSD: options.mk,v 1.1 2012/10/21 18:50:54 darcy Exp $

PKG_OPTIONS_VAR=         PKG_OPTIONS.freeswitch
PKG_SUPPORTED_OPTIONS=   freeswitch-08k freeswitch-16k freeswitch-32k freeswitch-48k
PKG_SUGGESTED_OPTIONS=   freeswitch-08k freeswitch-16k

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfreeswitch-08k)
DISTFILES+=		freeswitch-sounds-fr-ca-june-8000-${VERSION}.tar.gz
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-16k)
DISTFILES+=		freeswitch-sounds-fr-ca-june-16000-${VERSION}.tar.gz
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-32k)
DISTFILES+=		freeswitch-sounds-fr-ca-june-32000-${VERSION}.tar.gz
.endif

.if !empty(PKG_OPTIONS:Mfreeswitch-48k)
DISTFILES+=		freeswitch-sounds-fr-ca-june-48000-${VERSION}.tar.gz
.endif
