# $NetBSD: Makefile,v 1.1 2016/02/25 19:48:38 fhajny Exp $

CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/sqldf/
COMMENT=	R package for running SQL statements on R data frames
LICENSE=	gnu-gpl-v2

R_PKGNAME=	sqldf
R_PKGVER=	0.4-10

DEPENDS+=	R-DBI>=0.2.5:../../math/R-DBI
DEPENDS+=	R-RSQLite>=1.0.0:../../databases/R-RSQLite
DEPENDS+=	R-chron>=2.3.42:../../math/R-chron
DEPENDS+=	R-gsubfn>=0.6:../../textproc/R-gsubfn
DEPENDS+=	R-proto>=0.3.9.2.6:../../devel/R-proto

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
