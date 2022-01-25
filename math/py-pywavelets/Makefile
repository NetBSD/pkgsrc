# $NetBSD: Makefile,v 1.7 2022/01/25 01:28:26 wiz Exp $

DISTNAME=	PyWavelets-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyWavelets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyWavelets/pywt/releases
COMMENT=	Discrete Wavelet Transforms in Python
LICENSE=	mit

REPLACE_PYTHON+=	pywt/tests/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	${PYTHONBIN} -c 'import pywt; pywt.test()'

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
