# $NetBSD: Makefile,v 1.3 2022/11/27 10:41:35 adam Exp $

DISTNAME=	pyhamcrest-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^pyh/h/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyHamcrest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hamcrest/PyHamcrest
COMMENT=	Framework for writing matcher objects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
