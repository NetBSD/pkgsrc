# $NetBSD: options.mk,v 1.17 2025/02/27 13:49:51 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuradio
PKG_SUPPORTED_OPTIONS=	alsa
# alsa        is said supported, but not good on NetBSD

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include	"../../audio/alsa-lib/buildlink3.mk"
ALSA_ENABLED=
CONF_FILES+=	${EGDIR}/gr-audio-alsa.conf	${PKG_SYSCONFDIR}/gr-audio-alsa.conf
PLIST_SRC+=	${PKGDIR}/PLIST.alsa
.else
# disable ALSA, see patches/patch-gr-audio_lib_CMakeLists.txt
ALSA_ENABLED=	\#
.endif
