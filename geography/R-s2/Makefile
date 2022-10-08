# $NetBSD: Makefile,v 1.4 2022/10/08 20:30:46 he Exp $

R_PKGNAME=	s2
R_PKGVER=	1.0.6
PKGREVISION=	1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spherical Geometry Operators Using the S2 Geometry Library
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-wk/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
