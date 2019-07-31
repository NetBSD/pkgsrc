# $NetBSD: Makefile,v 1.13 2019/07/31 19:29:34 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/gdata/
COMMENT=	Various R programming tools for data manipulation
LICENSE=	gnu-gpl-v2

R_PKGNAME=	gdata
R_PKGVER=	2.18.0

DEPENDS+=	R-gtools>=3.5.0:../../math/R-gtools

USE_TOOLS+=	perl:run
REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
