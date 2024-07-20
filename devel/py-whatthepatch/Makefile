# $NetBSD: Makefile,v 1.4 2024/07/20 06:24:44 adam Exp $

DISTNAME=	whatthepatch-1.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/whatthepatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cscorley/whatthepatch
COMMENT=	Patch parsing and application library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.0.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
