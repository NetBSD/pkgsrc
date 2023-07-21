# $NetBSD: Makefile,v 1.2 2023/07/21 08:20:53 jperkin Exp $

DISTNAME=	colormath-3.0.0
PKGNAME=	${PYPKGPREFIX}-colormath-3.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colormath/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://pypi.org/project/colormath/
COMMENT=	Module that spares the user from directly dealing with color math
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.9.1:../../math/py-networkx

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
