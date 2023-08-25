# $NetBSD: Makefile,v 1.10 2023/08/25 16:02:49 adam Exp $

DISTNAME=	jplephem-2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jplephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brandon-rhodes/python-jplephem
COMMENT=	Python module to load a JPL ephemeris for dynamical calculations
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
