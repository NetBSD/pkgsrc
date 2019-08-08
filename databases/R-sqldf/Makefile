# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:37 brook Exp $

R_PKGNAME=	sqldf
R_PKGVER=	0.4-11
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Manipulate R data frames using SQL
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-RSQLite>=1.0.0:../../databases/R-RSQLite
DEPENDS+=	R-proto>=1.0.0:../../devel/R-proto
DEPENDS+=	R-DBI>=1.0.0:../../math/R-DBI
DEPENDS+=	R-chron>=2.3.47:../../math/R-chron
DEPENDS+=	R-gsubfn>=0.6:../../textproc/R-gsubfn

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
