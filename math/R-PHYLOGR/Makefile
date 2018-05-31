# $NetBSD: Makefile,v 1.8 2018/05/31 01:58:17 wen Exp $
#

CATEGORIES=		databases math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

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
