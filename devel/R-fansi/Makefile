# $NetBSD: Makefile,v 1.4 2021/06/05 08:05:51 mef Exp $

R_PKGNAME=	fansi
R_PKGVER=	0.5.0
CATEGORIES=	devel

MAINTAINER=	wen@NetBSD.org
COMMENT=	ANSI control sequence aware string functions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

#EST_DEPENDS+=	R-unitizer-[0-9]*:../../devel/R-unitizer
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
