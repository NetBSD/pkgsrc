# $NetBSD: Makefile,v 1.12 2023/08/29 07:38:04 adam Exp $

DISTNAME=	limits-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/limits/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://limits.readthedocs.org/
COMMENT=	Rate limiting utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.3:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-packaging>=21:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
