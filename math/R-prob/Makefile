# $NetBSD: Makefile,v 1.2 2018/07/28 14:53:46 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prob.r-forge.r-project.org/
COMMENT=	Elementary probability on finite sample spaces
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-combinat-[0-9]*:../../math/R-combinat
DEPENDS+=	R-fAsianOptions-[0-9]*:../../finance/R-fAsianOptions

R_PKGNAME=	prob
R_PKGVER=	1.0-0

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
