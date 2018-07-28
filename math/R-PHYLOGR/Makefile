# $NetBSD: Makefile,v 1.9 2018/07/28 14:40:45 brook Exp $
#

CATEGORIES=		databases math

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${R_HOMEPAGE_BASE}/PHYLOGR/
COMMENT=		Manipulation of phylogenetically simulated data sets using GLS
LICENSE=		gnu-gpl-v2

R_PKGNAME=		PHYLOGR
R_PKGVER=		1.0.10

post-extract:
	echo 'exportPattern("^[^\\.]")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
