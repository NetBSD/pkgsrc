# $NetBSD: Makefile,v 1.19 2026/05/08 16:59:01 wiz Exp $

DISTNAME=	biopython-1.87
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	310

# tests fail because pypi distfile is missing a lot of the required files

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
