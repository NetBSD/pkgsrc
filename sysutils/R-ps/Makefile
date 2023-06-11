# $NetBSD: Makefile,v 1.7 2023/06/11 10:52:42 mef Exp $

R_PKGNAME=	ps
R_PKGVER=	1.7.5
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	List, query, manipulate system processes
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-pingr-[0-9]*:../../net/R-pingr
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-pillar-[0-9]*:../../misc/R-pillar
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
