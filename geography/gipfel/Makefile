# $NetBSD: Makefile,v 1.28 2023/11/12 13:21:46 wiz Exp $

DISTNAME=	gipfel-0.4.1
PKGREVISION=	2
CATEGORIES=	geography graphics
MASTER_SITES=	https://flpsed.org/

MAINTAINER=	johannes.hofmann@gmx.de
HOMEPAGE=	https://flpsed.org/gipfel.html
COMMENT=	Photogrammetry for mountain images
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
