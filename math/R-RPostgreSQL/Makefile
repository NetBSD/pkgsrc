# $NetBSD: Makefile,v 1.10 2022/04/25 12:26:46 mef Exp $

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.7-3

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
