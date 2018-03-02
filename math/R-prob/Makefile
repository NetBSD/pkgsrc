# $NetBSD: Makefile,v 1.1 2018/03/02 19:04:13 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/Archive/prob/}

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
