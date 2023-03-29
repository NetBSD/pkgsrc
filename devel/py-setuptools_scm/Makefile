# $NetBSD: Makefile,v 1.38 2023/03/29 09:34:09 wiz Exp $

DISTNAME=	setuptools_scm-7.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools_scm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools_scm
COMMENT=	Manage your versions by scm tags
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=45:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-mercurial-[0-9]*:../../devel/py-mercurial
TEST_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20:../../devel/py-virtualenv

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.0.0:../../textproc/py-tomli
.endif

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
# needs to be installed for testing, otherwise you'll see
# INTERNALERROR> importlib.metadata.PackageNotFoundError: No package metadata was found for setuptools_scm
# as of 7.1.0:
# 1 failed, 217 passed, 33 skipped, 3 xfailed, 1 xpassed
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
