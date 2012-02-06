# $NetBSD: Makefile,v 1.25 2012/02/06 12:41:21 wiz Exp $
#

DISTNAME=	img2eps-0.2
PKGREVISION=	10
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
TEST_TARGET=	check

LDFLAGS.DragonFly=	-lm

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
