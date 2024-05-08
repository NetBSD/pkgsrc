# $NetBSD: Makefile,v 1.11 2024/05/08 12:54:39 adam Exp $

DISTNAME=	pyerfa-2.0.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyerfa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liberfa/pyerfa
COMMENT=	Python wrapper for ERFA library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.19:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	erfa>=2.0.0:../../math/erfa
TEST_DEPENDS+=	${PYPKGPREFIX}-test-doctestplus>=0.7:../../devel/py-test-doctestplus

MAKE_ENV+=	PYERFA_USE_SYSTEM_LIBERFA=1

USE_LIBTOOL=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/erfa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
