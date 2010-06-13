# $NetBSD: Makefile,v 1.19 2010/06/13 22:45:15 wiz Exp $
#

DISTNAME=	img2eps-0.2
PKGREVISION=	6
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/

OWNER=		dillo@NetBSD.org
HOMEPAGE=	http://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
TEST_TARGET=	check

.include "options.mk"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
