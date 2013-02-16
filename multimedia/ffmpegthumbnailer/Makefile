# $NetBSD: Makefile,v 1.14 2013/02/16 11:18:02 wiz Exp $
#

DISTNAME=	ffmpegthumbnailer-2.0.8
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://ffmpegthumbnailer.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ffmpegthumbnailer/
COMMENT=	Lightweight video thumbnailer that can be used by file managers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libffmpegthumbnailer.pc.in

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
