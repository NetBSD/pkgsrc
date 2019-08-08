# $NetBSD: Makefile,v 1.8 2019/08/08 19:53:45 brook Exp $

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.6-2
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to the PostgreSQL database system
LICENSE=	gnu-gpl-v2	# OR file LICENSE

DEPENDS+=	R-DBI>=0.3:../../math/R-DBI

USE_TOOLS+=	sh
REPLACE_SH+=	${WRKSRC}/inst/devTests/copyTest.sh
USE_LANGUAGES=	c

CHECK_INTERPRETER_SKIP=	lib/R/library/RPostgreSQL/devTests/*

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
