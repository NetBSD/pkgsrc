# $NetBSD: Makefile,v 1.5 2016/04/09 08:30:36 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/plyr/
COMMENT=	Tools for splitting, applying and combining data
LICENSE=	mit

R_PKGNAME=	plyr
R_PKGVER=	1.8.3

USE_LANGUAGES+=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
