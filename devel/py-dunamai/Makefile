# $NetBSD: Makefile,v 1.3 2026/04/05 11:35:14 wiz Exp $

DISTNAME=	dunamai-1.26.1
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

# as of 1.26.1
# 10 failed, 47 passed, 6 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
