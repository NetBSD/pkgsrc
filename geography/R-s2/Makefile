# $NetBSD: Makefile,v 1.1 2021/09/20 06:08:07 mef Exp $

R_PKGNAME=	s2
R_PKGVER=	1.0.6
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spherical Geometry Operators Using the S2 Geometry Library
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-wk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
