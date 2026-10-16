# $NetBSD: Makefile,v 1.16 2026/10/16 19:43:50 adam Exp $

DISTNAME=	lockfile-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lockfile/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/smontanaro/pylockfile/
COMMENT=	Platform-independent file locking module
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=1.8:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx via py-pbr

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
