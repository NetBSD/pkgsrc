# $NetBSD: Makefile,v 1.10 2004/02/20 11:33:21 jmmv Exp $
#

DISTNAME=		gst-plugins-0.6.4
PKGREVISION=		1
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gst-plugins/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		gstreamer plugins

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	gst-libs/gst/gconf/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-play.pc.in
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${PREFIX}/include/cdparanoia
CONFIGURE_ARGS+=	--disable-arts
CONFIGURE_ARGS+=	--disable-artsc
CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-qcam
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	gstreamer.schemas

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	"Fixing path to OSS audio device."
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

pre-install:
	${ECHO} "install:" >${WRKSRC}/gst-libs/ext/ffmpeg/Makefile

.include "../../audio/cdparanoia/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libsidplay/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hermes/buildlink3.mk"
.include "../../graphics/openquicktime/buildlink3.mk"
.include "../../graphics/swfdec/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
