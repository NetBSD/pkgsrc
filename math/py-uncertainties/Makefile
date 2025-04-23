# $NetBSD: Makefile,v 1.22 2025/04/23 15:11:31 adam Exp $

DISTNAME=	uncertainties-3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncertainties/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uncertainties-python-package.readthedocs.io/
COMMENT=	Transparent calculations with uncertainties on the quantities involved
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
