# $NetBSD: Makefile,v 1.15 2024/11/11 07:28:41 wiz Exp $

DISTNAME=	jplephem-2.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jplephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brandon-rhodes/python-jplephem
COMMENT=	Python module to load a JPL ephemeris for dynamical calculations
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy

USE_LANGUAGES=	# none

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
