# $NetBSD: Makefile,v 1.4 2021/06/29 08:42:01 nia Exp $

DISTNAME=	PyWavelets-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyWavelets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyWavelets/pywt/releases
COMMENT=	Discrete Wavelet Transforms in Python
LICENSE=	mit

REPLACE_PYTHON+=	pywt/tests/*.py

do-test:
	${PYTHONBIN} -c 'import pywt; pywt.test()'

PYTHON_VERSIONS_INCOMPATIBLE+=	36	# py-numpy

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
