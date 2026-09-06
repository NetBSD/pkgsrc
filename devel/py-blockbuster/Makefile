# $NetBSD: Makefile,v 1.1 2026/09/06 17:01:36 adam Exp $

DISTNAME=	blockbuster-1.5.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/blockbuster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cbornet/blockbuster
COMMENT=	Utility to detect blocking calls in the async event loop
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-forbiddenfruit>=0.1.4:../../misc/py-forbiddenfruit

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
