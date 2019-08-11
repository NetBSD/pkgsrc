# $NetBSD: Makefile,v 1.15 2019/08/11 13:21:43 wiz Exp $

R_PKGNAME=	gdata
R_PKGVER=	2.18.0
PKGREVISION=	1
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
