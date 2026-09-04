# $NetBSD: Makefile,v 1.22 2026/09/04 06:45:20 adam Exp $

DISTNAME=	twine-7.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://twine.readthedocs.io/
COMMENT=	Collection of utilities for publishing packages on PyPI
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-id>=0:../../devel/py-id
DEPENDS+=	${PYPKGPREFIX}-keyring>=21.2.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.1:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-readme_renderer>=35.0:../../textproc/py-readme_renderer
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rich>=14.3.3:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-rfc3986>=1.4.0:../../www/py-rfc3986
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.0:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-build>=0:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend>=0:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket>=0:../../devel/py-test_socket

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	twine

# as of 6.2.0
# 1 failed, 228 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
