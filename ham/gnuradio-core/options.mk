# $NetBSD: options.mk,v 1.16 2024/10/14 06:45:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuradio
PKG_SUPPORTED_OPTIONS=	filter-design alsa
# alsa        is said supported, but not good on NetBSD

PKG_SUGGESTED_OPTIONS=	filter-design

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfilter-design)
PYTHON_VERSIONS_INCOMPATIBLE+=	313
DEPENDS+=	${PYPKGPREFIX}-qtgraph-qt5-[0-9]*:../../x11/py-qtgraph-qt5
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include	"../../audio/alsa-lib/buildlink3.mk"
ALSA_ENABLED=
CONF_FILES+=	${EGDIR}/gr-audio-alsa.conf	${PKG_SYSCONFDIR}/gr-audio-alsa.conf
PLIST_SRC+=	${PKGDIR}/PLIST.alsa
.else
# disable ALSA, see patches/patch-gr-audio_lib_CMakeLists.txt
ALSA_ENABLED=	\#
.endif
