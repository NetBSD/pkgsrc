# $NetBSD: Makefile,v 1.21 2026/10/16 19:43:40 adam Exp $

DISTNAME=	biopython-1.87
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	311

# tests fail because pypi distfile is missing a lot of the required files

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
