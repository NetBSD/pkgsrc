# $NetBSD: Makefile,v 1.6 2026/10/18 12:23:06 wiz Exp $

DISTNAME=	dunamai-1.26.3
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

# as of 1.26.3
# 60 passed, 6 skipped, 54 warning
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
