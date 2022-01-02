# $NetBSD: Makefile,v 1.4 2022/01/02 09:20:57 wiz Exp $

DISTNAME=	jplephem-2.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jplephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brandon-rhodes/python-jplephem
COMMENT=	Python module to load a JPL ephemeris for dynamical calculations
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
