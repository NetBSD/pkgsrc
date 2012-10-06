# $NetBSD: Makefile,v 1.4 2012/10/06 14:11:17 asau Exp $
#

DISTNAME=	pyfits-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://www.stsci.edu/resources/software_hardware/pyfits/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
#LICENSE=	# TODO: (see mk/license.mk)

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

pre-configure:
	${MV} ${WRKSRC}/scripts/fitscheck \
	      ${WRKSRC}/scripts/fitscheck${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
