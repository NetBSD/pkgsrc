# $NetBSD: Makefile,v 1.12 2022/01/10 09:07:17 wiz Exp $

DISTNAME=	PyFFTW3-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/FFTW/fftw/S/3//}
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyFFTW3/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/PyFFTW3
COMMENT=	Python bindings to the FFTW3 C-library
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	27 # as of 0.2.1

MAKE_ENV+=	FFTW_PATH=${PREFIX}/lib

.include "../../lang/python/egg.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
