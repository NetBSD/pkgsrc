# $NetBSD: Makefile,v 1.1 2020/01/11 07:05:15 mef Exp $

DISTNAME=	RUnit_0.4.32
CATEGORIES=	devel
MASTER_SITES=	https://cran.rstudio.com/src/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cran.rstudio.com/web/packages/RUnit/index.html
COMMENT=	R functions implementing a standard Unit Testing framework

LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML

#WRKSRC=		${WRKDIR}/RUnit
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
