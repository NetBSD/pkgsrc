# $NetBSD: Makefile,v 1.10 2016/03/07 18:42:37 nros Exp $

PKGNAME=	kodi-15.2
PKGREVISION=	4
DISTNAME=	15.2-Isengard
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.kodi.tv/releases/source/

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	http://kodi.tv/
COMMENT=	Open source software media center
LICENSE=	gnu-gpl-v2

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

EXTRACT_USING=	gtar

WRKSRC=			${WRKDIR}/xbmc-15.2-Isengard
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config automake autoconf autoreconf gawk gmake bash
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_JAVA=		build
USE_JAVA2=		yes
GNU_CONFIGURE=		yes

CONFIG_SHELL=		${TOOLS_PATH.bash}
CONFIG_GUESS_OVERRIDE=  lib/libmpeg2/.auto/config.guess \
			tools/depends/build-aux/config.guess
CONFIG_SUB_OVERRIDE=    lib/libmpeg2/.auto/config.sub \
			tools/depends/build-aux/config.sub

CONFIGURE_ENV+=		ac_cv_path_SWIG_EXE=${PREFIX}/bin/swig2.0

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # insists on < 3.0 as of 15.2

# These need to be ported
CONFIGURE_ARGS+=	--disable-projectm
CONFIGURE_ARGS+=	--disable-rsxs

PKGCONFIG_OVERRIDE+=	lib/libdvd/libdvdcss/src/libdvdcss.pc.in
PKGCONFIG_OVERRIDE+=	lib/libdvd/libdvdnav/misc/dvdnav.pc.in
PKGCONFIG_OVERRIDE+=	lib/libdvd/libdvdnav/misc/dvdnavmini.pc.in
PKGCONFIG_OVERRIDE+=	lib/libdvd/libdvdread/misc/dvdread.pc.in
PKGCONFIG_OVERRIDE+=	lib/libmpeg2/libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	lib/libmpeg2/libmpeg2/libmpeg2.pc.in
PKGCONFIG_OVERRIDE+=	tools/depends/native/libsquish-native/src/squish.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/visualizations/Goom/goom2k4-0/libgoom2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/visualizations/XBMCProjectM/libprojectM/libprojectM.pc.in

PLIST_SUBST+=	MACHINE_CPU=${MACHINE_CPU}

pre-configure:
	cd ${WRKSRC} && ${SH} ./bootstrap

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
#.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/mysql55-client/buildlink3.mk"
#.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../misc/libcec/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../multimedia/libbluray/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
#.include "../../multimedia/libvdpau/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
