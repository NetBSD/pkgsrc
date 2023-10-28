# $NetBSD: Makefile,v 1.12 2023/10/28 19:56:59 wiz Exp $

DISTNAME=	entrypoints-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/entrypoints/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/takluyver/entrypoints
COMMENT=	Discover and load entry points from installed packages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=2:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
