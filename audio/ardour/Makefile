# $NetBSD: Makefile,v 1.45 2020/11/05 09:07:23 ryoon Exp $

DISTNAME=	Ardour-5.12.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	11
CATEGORIES=	audio
# currently, distfiles must be downloaded by hand from ardour.org
# and uploaded using `make upload-distfiles`.
# there is no canonical URL, only https://community.ardour.org/srctar
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ardour.org/
COMMENT=	Digital Audio Workstation
LICENSE=	gnu-gpl-v2

UNLIMIT_RESOURCES=	stacksize

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++11

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

EGDIR=		${PREFIX}/share/examples/ardour5

WAF_ENV+=	EGDIR=${EGDIR}

PKG_SYSCONFSUBDIR=	ardour5

CONF_FILES+=	${EGDIR}/ardour.keys ${PKG_SYSCONFDIR}/ardour.keys
CONF_FILES+=	${EGDIR}/ardour.menus ${PKG_SYSCONFDIR}/ardour.menus
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

# Does not set runtime search path for internal libraries...

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-comp.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-delay.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-eq.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-fluidsynth.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-reverb.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/LV2/a-reasonablesynth.lv2
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/backends
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/engines
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/panners
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/surfaces
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/utils
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/ardour5/vamp

# strdup prototype difficulties...
CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

WAF_REPLACE_EXECUTABLE=		no
# No release with python 3 support yet.
# Patches are available.
PYTHON_VERSIONS_ACCEPTED=	27
PYTHON_FOR_BUILD_ONLY=		tool

INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications

pre-patch:
	cd ${WRKSRC} && ${PYTHONBIN} waf --help > /dev/null
	rm ${WRKSRC}/.waf-1.6.11-06ee4b7efbeab1252ed3b11499834d2a/waflib/Tools/c_config.pyc

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour5.appdata.xml \
	    ${DESTDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/build/gtk2_ardour/ardour5.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in 16 22 32 48 256 512
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${DESTDIR}${PREFIX}/share/ardour5/resources/Ardour-icon_${s}px.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/ardour5.png
.endfor

.include "../../devel/waf/waf.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/aubio/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/rubberband/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
