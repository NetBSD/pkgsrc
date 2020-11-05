# $NetBSD: Makefile,v 1.3 2020/11/05 09:08:15 ryoon Exp $

R_PKGNAME=	lwgeom
R_PKGVER=	0.2-5
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings to Selected 'liblwgeom' Functions for Simple Features
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-units>=0.6.5:../../math/R-units

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-sf/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
