# $NetBSD: Makefile,v 1.62 2022/08/11 05:08:01 gutteridge Exp $

DISTNAME=	Ardour-6.9.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	8
CATEGORIES=	audio
# currently, distfiles must be downloaded by hand from ardour.org
# and uploaded using `make upload-distfiles`.
# there is no canonical URL, only https://community.ardour.org/srctar
MASTER_SITES=	https://ftp.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ardour.org/
COMMENT=	Digital Audio Workstation
LICENSE=	gnu-gpl-v2

UNLIMIT_RESOURCES=	stacksize

USE_TOOLS+=	pkg-config perl itstool msgfmt perl
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

EGDIR=		${PREFIX}/share/examples/ardour6

WAF_ENV+=	EGDIR=${EGDIR}

PKG_SYSCONFSUBDIR=	ardour6

CONF_FILES+=	${EGDIR}/ardour.keys ${PKG_SYSCONFDIR}/ardour.keys
CONF_FILES+=	${EGDIR}/ardour.menus ${PKG_SYSCONFDIR}/ardour.menus
CONF_FILES+=	${EGDIR}/clearlooks.ardoursans.rc ${PKG_SYSCONFDIR}/clearlooks.ardoursans.rc
CONF_FILES+=	${EGDIR}/clearlooks.rc ${PKG_SYSCONFDIR}/clearlooks.rc
CONF_FILES+=	${EGDIR}/default_ui_config ${PKG_SYSCONFDIR}/default_ui_config
CONF_FILES+=	${EGDIR}/system_config ${PKG_SYSCONFDIR}/system_config
CONF_FILES+=	${EGDIR}/trx.menus ${PKG_SYSCONFDIR}/trx.menus

ARD_BACKENDS=	dummy

.include "options.mk"

WAF_ARGS+=	--with-backends=${ARD_BACKENDS:ts,}
WAF_ARGS+=	--keepflags
WAF_ARGS+=	--noconfirm
WAF_ARGS+=	--dist-target=none
WAF_ARGS+=	--cxx11
WAF_ARGS+=	--freedesktop
WAF_ARGS+=	--no-phone-home
WAF_ARGS+=	--no-vst3
WAF_ARGS+=	--use-external-libs
WAF_ARGS+=	--nls

# Does not set runtime search path for internal libraries...

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-comp.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-delay.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-eq.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-fluidsynth.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-reverb.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/LV2/a-reasonablesynth.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/backends
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/engines
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/panners
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/surfaces
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/utils
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour6/vamp

# strdup prototype difficulties...
CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

WAF_REPLACE_EXECUTABLE=		no
# No release with python 3 support yet.
# Patches are available.
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour6.appdata.xml \
	    ${DESTDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour6.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in 16 22 32 48 256 512
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/share/ardour6/resources/Ardour-icon_${s}px.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/ardour6.png
.endfor

.include "../../devel/waf/waf.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/aubio/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/libltc/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/rubberband/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
