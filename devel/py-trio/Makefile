# $NetBSD: Makefile,v 1.30 2026/10/16 18:13:06 adam Exp $

DISTNAME=	trio-0.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-trio/trio
COMMENT=	Friendly Python library for async concurrency and I/O
LICENSE=	mit OR apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-attrs>=23.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-idna>=0:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-outcome>=0:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.3.0:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=0:../../devel/py-sortedcontainers
TEST_DEPENDS+=	${PYPKGPREFIX}-astor>=0.8.1:../../devel/py-astor
TEST_DEPENDS+=	${PYPKGPREFIX}-async_generator>=0:../../devel/py-async_generator
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-jedi>=0:../../editors/py-jedi
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>=0:../../devel/py-pylint
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio>=0:../../devel/py-test-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

# as of 0.32.0, needs ctrl-c a couple times to finish
# 11 failed, 806 passed, 74 skipped, 3 xfailed

# for tests
USE_LANGUAGES=	c

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL:test
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
