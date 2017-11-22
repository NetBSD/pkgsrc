# $NetBSD: Makefile,v 1.1 2017/11/22 11:06:23 markd Exp $

DISTNAME=	PyWavelets-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyWavelets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyWavelets/pywt/releases
COMMENT=	Discrete Wavelet Transforms in Python
LICENSE=	mit

REPLACE_PYTHON+=	pywt/tests/*.py

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
