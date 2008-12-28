# $NetBSD: Makefile,v 1.1.1.1 2008/12/28 12:32:15 jmcneill Exp $
#

DISTNAME=	ffmpegthumbnailer-1.3.0
CATEGORIES=	multimedia
MASTER_SITES=	http://ffmpegthumbnailer.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ffmpegthumbnailer/
COMMENT=	Lightweight video thumbnailer that can be used by file managers

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libffmpegthumbnailer.pc.in

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
