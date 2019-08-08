# $NetBSD: Makefile,v 1.4 2019/08/08 19:53:52 brook Exp $

R_PKGNAME=	prob
R_PKGVER=	1.0-1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Elementary probability on finite sample spaces
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-fAsianOptions>=3042.82:../../finance/R-fAsianOptions
DEPENDS+=	R-combinat>=0.0.8:../../math/R-combinat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
