# $NetBSD: Makefile,v 1.9 2026/11/08 18:12:55 wiz Exp $

DISTNAME=	lap-0.5.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gatagat/lap
COMMENT=	Linear Assignment Problem solver (LAPJV/LAPMOD)
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	311

USE_LANGUAGES=	c c++

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=3.3.0nb1
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
