# $NetBSD: Makefile,v 1.5 2016/08/28 17:47:47 wiz Exp $

DISTNAME=	pyfits-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfits/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-stsci.distutils-[0-9]*:../../devel/py-stsci.distutils

REPLACE_PYTHON=	lib/pyfits/core.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fitscheck fitscheck${PYVERSSUFFIX} && \
		${MV} fitsdiff fitsdiff${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
