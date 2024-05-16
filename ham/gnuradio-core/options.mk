# $NetBSD: options.mk,v 1.10 2024/05/16 20:02:20 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnuradio
PKG_SUPPORTED_OPTIONS=	ninja-build filter-design alsa
# ninja-build is said supported, but not working
# alsa        is said supported, but not good on NetBSD

# Adding ninja-build to following line (now) stops
# [164/850] cd /PATH/ham/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# FAILED: cd /PATH/ham/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# : permission denied

PKG_SUGGESTED_OPTIONS=	filter-design

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mninja-build)
CMAKE_ARGS+=	-GNinja
TOOL_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

do-build:
	(cd ${WRKSRC}/build; ninja)
.else
do-build:
	(cd ${WRKSRC}/build; ${BUILD_MAKE_CMD})
.endif

.if !empty(PKG_OPTIONS:Mfilter-design)
PYTHON_VERSIONS_INCOMPATIBLE+=	27 38 312
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
