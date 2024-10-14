# $NetBSD: Makefile,v 1.17 2024/10/14 06:45:51 wiz Exp $

DISTNAME=	pywavelets-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyWavelets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyWavelets/pywt/releases
COMMENT=	Discrete Wavelet Transforms in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.4:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python>=0.16.0:../../devel/py-meson_python

REPLACE_PYTHON+=	pywt/data/create_dat.py
REPLACE_PYTHON+=	pywt/tests/*.py

USE_CC_FEATURES=		c17

pre-configure:
	${LN} -sf ${PREFIX}/bin/cython-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/cython

do-test:
	cd ${WRKDIR} && ${PYTHONBIN} -c 'import pywt; pywt.test()'

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
