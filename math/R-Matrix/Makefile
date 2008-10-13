# $NetBSD: Makefile,v 1.4 2008/10/13 11:22:46 markd Exp $
#

CATEGORIES=		databases math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/Matrix/
COMMENT=		Classes and methods for numerical linear algebra

R_PKGNAME=		Matrix
R_PKGVER=		0.999375-15

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
