# $NetBSD: Makefile,v 1.14 2024/05/20 07:44:37 adam Exp $

DISTNAME=	pytest-xprocess-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-xprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytest-dev/pytest-xprocess
COMMENT=	Pytest plugin to manage external processes across test runs
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=45.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2.3:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
