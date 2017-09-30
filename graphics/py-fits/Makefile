# $NetBSD: Makefile,v 1.6 2017/09/30 10:10:04 adam Exp $

DISTNAME=	pyfits-3.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfits/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-d2to1>=0.2.12:../../devel/py-d2to1
BUILD_DEPENDS+=	${PYPKGPREFIX}-stsci.distutils>=0.3:../../devel/py-stsci.distutils

REPLACE_PYTHON=	lib/pyfits/core.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fitscheck fitscheck${PYVERSSUFFIX} && \
		${MV} fitsdiff fitsdiff${PYVERSSUFFIX} && \
		${MV} fitshead fitshead${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
