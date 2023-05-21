# $NetBSD: Makefile,v 1.10 2023/05/21 18:47:56 wiz Exp $

DISTNAME=	pygls-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygls/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/openlawlibrary/pygls
COMMENT=	Pythonic generic implementation of the Language Server Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.3:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-lsprotocol-[0-9]*:../../lang/py-lsprotocol
DEPENDS+=	${PYPKGPREFIX}-typeguard>=2.10.0:../../devel/py-typeguard
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.18.3:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
