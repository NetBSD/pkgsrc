# $NetBSD: Makefile,v 1.34 2017/11/06 13:26:52 wiz Exp $

DISTNAME=	img2eps-0.2
PKGREVISION=	14
CATEGORIES=	print graphics
MASTER_SITES=	https://www.nih.at/img2eps/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nih.at/img2eps/
COMMENT=	Convert raster images to EPS files
LICENSE=	modified-bsd AND original-bsd

GNU_CONFIGURE=	YES
TEST_TARGET=	check

LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
