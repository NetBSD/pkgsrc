# $NetBSD: Makefile,v 1.3 2023/01/29 21:16:26 ryoon Exp $

R_PKGNAME=	ragg
R_PKGVER=	1.2.4
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
