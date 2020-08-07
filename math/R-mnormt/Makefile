# $NetBSD: Makefile,v 1.1 2020/08/07 02:43:00 brook Exp $

CATEGORIES=	math R
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mnormt/
COMMENT=	Multivariate normal and t distributions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	mnormt
R_PKGVER=	1.5-6

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
