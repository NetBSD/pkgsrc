# $NetBSD: Makefile,v 1.5 2012/10/16 08:00:52 wiz Exp $
#

DISTNAME=	pyfits-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.stsci.edu/resources/software_hardware/pyfits/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.stsci.edu/resources/software_hardware/pyfits
COMMENT=	Python module for reading, writing, and manipulating FITS files
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
REPLACE_PYTHON=	lib/core.py

pre-configure:
	${MV} ${WRKSRC}/scripts/fitscheck \
	      ${WRKSRC}/scripts/fitscheck${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
