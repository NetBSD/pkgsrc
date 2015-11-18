# $NetBSD: Makefile,v 1.18 2015/11/18 14:19:51 ryoon Exp $

DISTNAME=	ffmpegthumbnailer-2.0.8
PKGREVISION=	5
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
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
