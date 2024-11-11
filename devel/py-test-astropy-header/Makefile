# $NetBSD: Makefile,v 1.2 2024/11/11 07:28:24 wiz Exp $

DISTNAME=	pytest-astropy-header-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-astropy-header/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/pytest-astropy-header
COMMENT=	Pytest plugin to add diagnostic information to the test output header
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-astropy-[0-9]*:../../math/py-astropy
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
