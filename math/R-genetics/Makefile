# $NetBSD: Makefile,v 1.5 2012/04/15 16:54:17 brook Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Classes and methods for handling genetic data
# LICENSE=	GPL (gnu-gpl-v?)

R_PKGNAME=	genetics
R_PKGVER=	1.3.6

DEPENDS+=	R-combinat>=0.0.8:../../math/R-combinat
DEPENDS+=	R-gdata>=2.8.2:../../math/R-gdata
DEPENDS+=	R-gtools>=2.6.2:../../math/R-gtools
DEPENDS+=	R-mvtnorm>=0.9.9992:../../math/R-mvtnorm

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
