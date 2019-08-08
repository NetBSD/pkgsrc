# $NetBSD: Makefile,v 1.14 2019/08/08 19:53:49 brook Exp $

R_PKGNAME=	gdata
R_PKGVER=	2.18.0
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various R programming tools for data manipulation
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-gtools>=3.5.0:../../math/R-gtools

USE_TOOLS+=	perl:run
REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
