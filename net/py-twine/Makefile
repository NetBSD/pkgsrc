# $NetBSD: Makefile,v 1.13 2024/05/18 07:07:43 adam Exp $

DISTNAME=	twine-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://twine.readthedocs.io/
COMMENT=	Collection of utilities for publishing packages on PyPI
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=45:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-keyring>=15.1:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.8.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-readme_renderer>=35.0:../../textproc/py-readme_renderer
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-rfc3986>=1.4.0:../../www/py-rfc3986
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.0:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test_socket-[0-9]*:../../devel/py-test_socket

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} twine twine-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
