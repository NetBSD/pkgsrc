# $NetBSD: options.mk,v 1.4 2019/06/15 17:54:22 adam Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.gnuradio
PKG_SUPPORTED_OPTIONS=  ninja-build filter-design alsa
# ninja-build is said supported, but not working
# alas        is said supported, but not good on NetBSD

# Adding ninja-build to following line (now) stops
# [164/850] cd /PATH/ham/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# FAILED: cd /PATH/ham/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# : permission denied

PKG_SUGGESTED_OPTIONS= filter-design

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mninja-build)
CMAKE_ARGS+=	-GNinja
BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

do-build:
	(cd ${WRKSRC}/build; ninja)
.else
do-build:
	(cd ${WRKSRC}/build; ${BUILD_MAKE_CMD})
.endif

.if !empty(PKG_OPTIONS:Mfilter-design)
# Running gr_filter_design asks for the package
DEPENDS+=		${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy12
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
