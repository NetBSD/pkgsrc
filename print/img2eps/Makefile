# $NetBSD: Makefile,v 1.32 2014/05/25 09:26:31 obache Exp $
#

DISTNAME=	img2eps-0.2
PKGREVISION=	13
CATEGORIES=	print graphics
MASTER_SITES=	http://www.nih.at/img2eps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files
LICENSE=	modified-bsd AND original-bsd

GNU_CONFIGURE=	YES
TEST_TARGET=	check

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
