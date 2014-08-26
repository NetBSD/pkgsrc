# $NetBSD: Makefile,v 1.2 2014/08/26 16:40:40 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/plyr/
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

R_PKGNAME=	plyr
R_PKGVER=	1.8.1

USE_LANGUAGES+=	c++

.include "../../math/R/Makefile.extension"
.include "../../math/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
