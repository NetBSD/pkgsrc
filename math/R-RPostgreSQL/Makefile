# $NetBSD: Makefile,v 1.9 2021/09/19 03:05:04 mef Exp $

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.7

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to the PostgreSQL database system
LICENSE=	gnu-gpl-v3 OR postgresql-license

DEPENDS+=	R-DBI>=0.3:../../math/R-DBI

USE_TOOLS+=	sh
REPLACE_SH+=	${WRKSRC}/inst/devTests/copyTest.sh

CHECK_INTERPRETER_SKIP=	lib/R/library/RPostgreSQL/devTests/*

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
