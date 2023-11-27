# $NetBSD: Makefile,v 1.1 2023/11/27 09:50:47 adam Exp $

DISTNAME=	jaraco.versioning-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.versioning
COMMENT=	More sophisticated version manipulation (than packaging)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=56:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
