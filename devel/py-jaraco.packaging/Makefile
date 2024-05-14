# $NetBSD: Makefile,v 1.1 2024/05/14 09:13:54 adam Exp $

DISTNAME=	jaraco_packaging-10.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.packaging
COMMENT=	Tools to supplement packaging Python releases
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/_/./}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
DEPENDS+=	${PYPKGPREFIX}-jaraco.context-[0-9]*:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.35:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-domdf-python-tools-[0-9]*:../../misc/py-domdf-python-tools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
