# $NetBSD: Makefile,v 1.13 2022/01/05 15:41:11 wiz Exp $

DISTNAME=	pyfits-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfits/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-d2to1>=0.2.12:../../devel/py-d2to1
BUILD_DEPENDS+=	${PYPKGPREFIX}-stsci.distutils>=0.3:../../devel/py-stsci.distutils

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fitscheck fitscheck-${PYVERSSUFFIX} && \
		${MV} fitsdiff fitsdiff-${PYVERSSUFFIX} && \
		${MV} fitshead fitshead-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
