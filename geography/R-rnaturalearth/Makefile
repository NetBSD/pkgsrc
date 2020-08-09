# $NetBSD: Makefile,v 1.1 2020/08/09 15:31:52 brook Exp $

R_PKGNAME=	rnaturalearth
R_PKGVER=	0.1.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	World Map Data from Natural Earth
LICENSE=	mit

DEPENDS+=	R-sf>=0.3.4:../../geography/R-sf

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
