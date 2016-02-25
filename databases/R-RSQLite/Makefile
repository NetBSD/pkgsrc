# $NetBSD: Makefile,v 1.1 2016/02/25 19:46:54 fhajny Exp $

CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RSQLite/
COMMENT=	Database Interface R driver for SQLite
LICENSE=	gnu-lgpl-v2

R_PKGNAME=	RSQLite
R_PKGVER=	1.0.0

DEPENDS+=	R-DBI>=0.3.1:../../math/R-DBI

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
