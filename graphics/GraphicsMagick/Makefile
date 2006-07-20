# $NetBSD: Makefile,v 1.1.1.1 2006/07/20 17:23:15 minskim Exp $
#

DISTNAME=	GraphicsMagick-1.1.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=graphicsmagick/} \
		ftp://ftp.graphicsmagick.org/pub/GraphicsMagick/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.graphicsmagick.org/
COMMENT=	X application for displaying and manipulating images

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config gs
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	magick/GraphicsMagick.pc.in \
			wand/GraphicsMagickWand.pc.in \
			Magick++/lib/GraphicsMagick++.pc.in

CONFIGURE_ARGS+=--without-perl

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
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
