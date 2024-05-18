# $NetBSD: Makefile,v 1.41 2024/05/18 06:18:44 adam Exp $

DISTNAME=	keyring-25.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/keyring/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://github.com/jaraco/keyring
COMMENT=	Store and access your passwords safely
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jaraco.classes>=0:../../devel/py-jaraco.classes
DEPENDS+=	${PYPKGPREFIX}-jaraco.context>=0:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-jaraco.functools>=0:../../devel/py-jaraco.functools
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.4.2:../../sysutils/py-jeepney
DEPENDS+=	${PYPKGPREFIX}-secretstorage>=3.2:../../security/py-secretstorage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 312
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.11.4:../../devel/py-importlib-metadata
.endif
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=0:../../devel/py-importlib-resources
.endif

REPLACE_PYTHON+=	keyring/cli.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} keyring keyring-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
