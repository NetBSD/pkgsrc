# $NetBSD: Makefile,v 1.14 2019/07/31 19:31:13 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Classes and methods for handling genetic data
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	perl

R_PKGNAME=	genetics
R_PKGVER=	1.3.8.1.2

DEPENDS+=	R-combinat>=0.0.8:../../math/R-combinat
DEPENDS+=	R-gdata>=2.18.0:../../math/R-gdata
DEPENDS+=	R-gtools>=3.5.0:../../math/R-gtools
DEPENDS+=	R-mvtnorm>=1.0.8:../../math/R-mvtnorm

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
