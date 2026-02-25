# $NetBSD: Makefile,v 1.4 2026/02/25 15:10:52 adam Exp $

DISTNAME=	lap-0.5.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gatagat/lap
COMMENT=	Linear Assignment Problem solver (LAPJV/LAPMOD)
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	310

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
