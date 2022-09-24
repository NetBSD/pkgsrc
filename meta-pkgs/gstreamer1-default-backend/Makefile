# $NetBSD: Makefile,v 1.3 2022/09/24 20:41:29 adam Exp $

DISTNAME=	gstreamer1-default-backend-1.1
CATEGORIES=	meta-pkgs audio multimedia
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Default audio backend for gstreamer1

META_PACKAGE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.gstreamer1-default-backend
PKG_SUPPORTED_OPTIONS=	alsa oss pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	alsa
.elif ${OSS_TYPE:tl} != "none"
PKG_SUGGESTED_OPTIONS=	oss
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
DEPENDS+=	gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.endif

.if !empty(PKG_OPTIONS:Moss)
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.endif

.if ${OPSYS} == "Darwin"
DEPENDS+=	gst-plugins1-osxaudio-[0-9]*:../../audio/gst-plugins1-osxaudio
DEPENDS+=	gst-plugins1-osxvideo-[0-9]*:../../multimedia/gst-plugins1-osxvideo
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
DEPENDS+=	gst-plugins1-pulse-[0-9]*:../../audio/gst-plugins1-pulse
.endif

.include "../../mk/bsd.pkg.mk"
