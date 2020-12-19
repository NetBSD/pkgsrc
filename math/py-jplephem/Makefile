# $NetBSD: Makefile,v 1.1 2020/12/19 14:23:00 mef Exp $

DISTNAME=	jplephem-2.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://files.pythonhosted.org/packages/c9/f0/e57456436531333455f40864622c5ae359654ccede8fe1156c3c2ac6c492/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jplephem/
COMMENT=	Python module to load a JPL ephemeris for dynamical calculations
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17.0:../../math/py-numpy

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
