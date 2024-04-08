# $NetBSD: Makefile,v 1.13 2024/04/08 05:52:10 adam Exp $

DISTNAME=	pywavelets-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyWavelets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyWavelets/pywt/releases
COMMENT=	Discrete Wavelet Transforms in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.15.0:../../devel/py-meson_python

REPLACE_PYTHON+=	pywt/data/create_dat.py
REPLACE_PYTHON+=	pywt/tests/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

do-test:
	${PYTHONBIN} -c 'import pywt; pywt.test()'

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
