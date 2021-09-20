# $NetBSD: Makefile,v 1.7 2021/09/20 03:35:09 mef Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.5-12.2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R graphics device using cairo graphics library
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png

USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
