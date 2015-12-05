# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:49 adam Exp $

DISTNAME=	PyFFTW3-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/FFTW/fftw/S/3//}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyFFTW3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/PyFFTW3
COMMENT=	Python bindings to the FFTW3 C-library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # as of 0.2.1

.include "../../lang/python/distutils.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
