# $NetBSD: Makefile,v 1.2 2021/12/30 13:05:38 adam Exp $

DISTNAME=	pyerfa-1.7.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyerfa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liberfa/pyerfa/
COMMENT=	Python wrapper for ERFA library
LICENSE=	modified-bsd

MAKE_ENV+=	PYERFA_USE_SYSTEM_LIBERFA=1

USE_LIBTOOL=	yes
USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=	erfa>=1.7.1:../../math/erfa

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/erfa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
