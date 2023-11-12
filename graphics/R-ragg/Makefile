# $NetBSD: Makefile,v 1.6 2023/11/12 13:21:50 wiz Exp $

R_PKGNAME=	ragg
R_PKGVER=	1.2.5
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphic Devices Based on AGG
LICENSE=	mit	# + file LICENSE

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../fonts/R-systemfonts/buildlink3.mk"
.include "../../fonts/R-textshaping/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
