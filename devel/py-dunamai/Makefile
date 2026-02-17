# $NetBSD: Makefile,v 1.2 2026/02/17 15:25:58 adam Exp $

DISTNAME=	dunamai-1.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dunamai/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mtkennerly/dunamai
COMMENT=	Dynamic version generation
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.9:../../devel/py-packaging

USE_LANGUAGES=	# none
# for testing
USE_TOOLS+=	git

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
