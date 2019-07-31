# $NetBSD: Makefile,v 1.8 2019/07/31 20:15:09 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/plyr/
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

R_PKGNAME=	plyr
R_PKGVER=	1.8.4

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
