# $NetBSD: Makefile,v 1.3 2019/07/31 20:19:10 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prob.r-forge.r-project.org/
COMMENT=	Elementary probability on finite sample spaces
LICENSE=	gnu-gpl-v3

R_PKGNAME=	prob
R_PKGVER=	1.0-1

DEPENDS+=	R-fAsianOptions>=3042.82:../../finance/R-fAsianOptions
DEPENDS+=	R-combinat>=0.0.8:../../math/R-combinat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
