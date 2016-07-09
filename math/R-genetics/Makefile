# $NetBSD: Makefile,v 1.11 2016/07/09 06:38:32 wiz Exp $
#

PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/genetics/
COMMENT=	Classes and methods for handling genetic data
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl

R_PKGNAME=	genetics
R_PKGVER=	1.3.8.1

DEPENDS+=	R-combinat>=0.0.8:../../math/R-combinat
DEPENDS+=	R-gdata>=2.8.2:../../math/R-gdata
DEPENDS+=	R-gtools>=2.6.2:../../math/R-gtools
DEPENDS+=	R-mvtnorm>=0.9.9992:../../math/R-mvtnorm

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
