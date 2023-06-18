# $NetBSD: Makefile,v 1.5 2023/06/18 14:42:29 mef Exp $

R_PKGNAME=	fansi
R_PKGVER=	1.0.4
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
COMMENT=	ANSI control sequence aware string functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

#EST_DEPENDS+=	R-unitizer-[0-9]*:../../devel/R-unitizer
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
