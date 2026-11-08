# $NetBSD: Makefile,v 1.7 2026/11/08 17:47:01 wiz Exp $

DISTNAME=	dunamai-1.26.4
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
USE_TOOLS+=	git:test

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
