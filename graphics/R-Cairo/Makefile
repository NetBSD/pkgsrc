# $NetBSD: Makefile,v 1.8 2023/01/29 21:16:26 ryoon Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.5-12.2
PKGREVISION=	1
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
