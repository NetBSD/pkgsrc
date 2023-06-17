# $NetBSD: Makefile,v 1.12 2023/06/17 11:20:55 mef Exp $

R_PKGNAME=	RPostgreSQL
R_PKGVER=	0.7-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	R interface to the PostgreSQL database system
LICENSE=	gnu-gpl-v3 OR postgresql-license

DEPENDS+=	R-DBI>=0.3:../../math/R-DBI

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	sh
REPLACE_SH+=	${WRKSRC}/inst/devTests/copyTest.sh

CHECK_INTERPRETER_SKIP=	lib/R/library/RPostgreSQL/devTests/*

.include "../../math/R/Makefile.extension"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
