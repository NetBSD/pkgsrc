# $NetBSD: Makefile,v 1.18 2025/07/03 19:18:08 wiz Exp $

DISTNAME=	jplephem-2.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jplephem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brandon-rhodes/python-jplephem
COMMENT=	Python module to load a JPL ephemeris for dynamical calculations
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
