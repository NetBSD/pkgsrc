# $NetBSD: Makefile,v 1.5 2021/06/05 08:13:45 mef Exp $

R_PKGNAME=	utf8
R_PKGVER=	1.2.1
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Unicode text processing
LICENSE=	apache-2.0

TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
