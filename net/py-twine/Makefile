# $NetBSD: Makefile,v 1.11 2023/10/28 19:57:13 wiz Exp $

DISTNAME=	twine-4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://twine.readthedocs.io/
COMMENT=	Collection of utilities for publishing packages on PyPI
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pkginfo>=1.8.1:../../devel/py-pkginfo
DEPENDS+=	${PYPKGPREFIX}-readme_renderer>=35.0:../../textproc/py-readme_renderer
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.9.1:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26.0:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-keyring>=15.1:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-rfc3986>=1.4.0:../../www/py-rfc3986
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
# unpackaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-socket-[0-9]*:../../*/py-test-socket
TEST_DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
#TEST_DEPENDS+=	${PYPKGPREFIX}-munch-[0-9]*:../../wip/py-munch
TEST_DEPENDS+=	${PYPKGPREFIX}-portend-[0-9]*:../../net/py-portend
TEST_DEPENDS+=	${PYPKGPREFIX}-jaraco.envs-[0-9]*:../../devel/py-jaraco.envs

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} twine twine-${PYVERSSUFFIX} || ${TRUE}

# as of 4.0.1
# 180 passed, 4 warnings, 10 errors
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
