# $NetBSD: Makefile,v 1.18 2025/04/12 08:08:52 adam Exp $

DISTNAME=	anytree-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anytree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/c0fec0de/anytree
COMMENT=	Powerful and Lightweight Python Tree Data Structure
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=2.0:../../devel/py-pdm_backend

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
