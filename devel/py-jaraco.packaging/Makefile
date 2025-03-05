# $NetBSD: Makefile,v 1.6 2025/03/05 09:46:39 wiz Exp $

DISTNAME=	jaraco_packaging-10.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.packaging
COMMENT=	Tools to supplement packaging Python releases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-build-[0-9]*:../../devel/py-build
DEPENDS+=	${PYPKGPREFIX}-jaraco.context-[0-9]*:../../devel/py-jaraco.context
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=20.0.35:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-domdf-python-tools-[0-9]*:../../misc/py-domdf-python-tools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
