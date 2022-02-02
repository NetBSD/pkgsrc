# $NetBSD: Makefile,v 1.11 2022/02/02 19:04:57 adam Exp $

DISTNAME=	pytest-asyncio-0.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-asyncio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-asyncio
COMMENT=	Pytest support for asyncio
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=5.7.1:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.5.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.931:../../lang/py-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>0:../../devel/py-typing-extensions
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
