# $NetBSD: Makefile,v 1.4 2023/02/19 02:26:03 mef Exp $

R_PKGNAME=	ragg
R_PKGVER=	1.2.5
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
