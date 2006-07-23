# $NetBSD: Makefile,v 1.3 2006/07/23 17:08:56 rillig Exp $
#

PKGREVISION=		1
CATEGORIES=		databases math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		${R_HOMEPAGE_BASE}/Matrix.html
COMMENT=		Classes and methods for numerical linear algebra

R_PKGNAME=		Matrix
R_PKGVER=		0.8-11

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
