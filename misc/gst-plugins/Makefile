# $NetBSD: Makefile,v 1.12 2003/12/13 00:45:24 wiz Exp $
#

DISTNAME=		gst-plugins-0.6.1
PKGREVISION=		8
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gst-plugins/0.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		gstreamer plugins

BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gst-libs/gst/gconf/gstreamer-gconf.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer-libs.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pkgconfig/gstreamer-play.pc.in
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${PREFIX}/include/cdparanoia
CONFIGURE_ARGS+=	--disable-ffmpeg
CONFIGURE_ARGS+=	--disable-qcam
CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	gstreamer.schemas

pre-install:
	${ECHO} "install:" >${WRKSRC}/gst-libs/ext/ffmpeg/Makefile

.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../audio/flac/buildlink2.mk"
.include "../../audio/gsm/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libsidplay/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/mjpegtools/buildlink2.mk"
.include "../../graphics/openquicktime/buildlink2.mk"
.include "../../graphics/swfdec/buildlink2.mk"
.include "../../misc/gstreamer/buildlink2.mk"
.include "../../misc/libdvdread/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
