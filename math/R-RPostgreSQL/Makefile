# $NetBSD: Makefile,v 1.1.1.1 2012/04/15 17:57:36 brook Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RPostgreSQL/
COMMENT=	R interface to the PostgreSQL database system
LICENSE=	gnu-gpl-v2 AND postgresql-license

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.3-2

DEPENDS+=	R-DBI>=0.2.5:../../math/R-DBI

USE_TOOLS+=	sh
REPLACE_SH+=	${WRKSRC}/inst/devTests/copyTest.sh

CHECK_INTERPRETER_SKIP=	lib/R/library/RPostgreSQL/devTests/*

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
