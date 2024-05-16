# $NetBSD: Makefile,v 1.6 2024/05/16 20:15:16 wiz Exp $

DISTNAME=	colormath-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colormath/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/gtaylor/python-colormath
COMMENT=	Module that spares the user from directly dealing with color math
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-networkx>=1.9.1:../../math/py-networkx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
