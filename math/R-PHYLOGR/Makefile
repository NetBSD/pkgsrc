# $NetBSD: Makefile,v 1.6 2013/12/07 19:32:48 dholland Exp $
#

CATEGORIES=		databases math
MASTER_SITES=		${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${R_HOMEPAGE_BASE}/PHYLOGR/
COMMENT=		Manipulation of phylogenetically simulated data sets using GLS
LICENSE=		gnu-gpl-v2

R_PKGNAME=		PHYLOGR
R_PKGVER=		1.0.7

post-extract:
	echo 'exportPattern("^[^\\.]")' > ${WRKSRC}/NAMESPACE

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
