# $NetBSD: Makefile,v 1.25.4.2 2010/02/22 13:21:41 tron Exp $
#

DISTNAME=	GraphicsMagick-1.3.11
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphicsmagick/} \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/1.3/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.graphicsmagick.org/
COMMENT=	X application for displaying and manipulating images

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config gs
USE_FEATURES=	vsnprintf		# optional but recommended for security
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	magick/GraphicsMagick.pc.in \
			wand/GraphicsMagickWand.pc.in \
			Magick++/lib/GraphicsMagick++.pc.in

CONFIGURE_ARGS+=	--without-perl

TEST_TARGET=	check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
