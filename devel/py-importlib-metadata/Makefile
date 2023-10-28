# $NetBSD: Makefile,v 1.37 2023/10/28 19:57:01 wiz Exp $

DISTNAME=	importlib_metadata-6.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/importlib-metadata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://importlib-metadata.readthedocs.io/
COMMENT=	Read metadata from Python packages
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-zipp>=0.5:../../archivers/py-zipp
TEST_DEPENDS+=	${PYPKGPREFIX}-fakefs-[0-9]*:../../devel/py-fakefs
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 309
TEST_DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
