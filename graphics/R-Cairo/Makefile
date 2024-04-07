# $NetBSD: Makefile,v 1.12 2024/04/07 07:34:07 wiz Exp $

R_PKGNAME=	Cairo
R_PKGVER=	1.6-0
PKGREVISION=	3
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
