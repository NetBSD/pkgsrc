# $NetBSD: Makefile,v 1.6 2026/08/12 22:02:47 wiz Exp $

DISTNAME=	orderly_set-5.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/orderly-set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/seperman/orderly-set
COMMENT=	Multiple implementations of ordered set
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=4:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark~=5.1.0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov~=6.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
