# $NetBSD: Makefile,v 1.26 2026/01/30 09:17:41 wiz Exp $

DISTNAME=	uncertainties-3.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncertainties/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uncertainties.readthedocs.io/en/latest/
COMMENT=	Transparent calculations with uncertainties on the quantities involved
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
