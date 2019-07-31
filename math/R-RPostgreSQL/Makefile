# $NetBSD: Makefile,v 1.7 2019/07/31 18:26:23 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RPostgreSQL/
COMMENT=	R interface to the PostgreSQL database system
LICENSE=	gnu-gpl-v2	# OR file LICENSE

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.6-2

DEPENDS+=	R-DBI>=0.3:../../math/R-DBI

USE_TOOLS+=	sh
REPLACE_SH+=	${WRKSRC}/inst/devTests/copyTest.sh
USE_LANGUAGES=	c

CHECK_INTERPRETER_SKIP=	lib/R/library/RPostgreSQL/devTests/*

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
