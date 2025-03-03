# $NetBSD: Makefile,v 1.23 2025/03/03 08:28:03 adam Exp $

DISTNAME=	limits-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/limits/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://limits.readthedocs.org/
COMMENT=	Rate limiting utilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-packaging>=21:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
