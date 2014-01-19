# $NetBSD: Makefile,v 1.1 2014/01/19 20:30:05 wiz Exp $

DISTNAME=	pyfits-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics
MASTER_SITES=	https://pypi.python.org/packages/source/p/pyfits/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
LICENSE=	modified-bsd

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	lib/pyfits/core.py

CONFLICTS=	${PYPKGPREFIX}-pyfits-[0-9]*

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fitscheck fitscheck${PYVERSSUFFIX} && \
		${MV} fitsdiff fitsdiff${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
