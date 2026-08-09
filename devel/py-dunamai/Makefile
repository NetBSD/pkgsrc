# $NetBSD: Makefile,v 1.5 2026/08/09 05:57:59 adam Exp $

DISTNAME=	dunamai-1.26.2
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

# as of 1.26.1
# 57 passed, 6 skipped, 49 warnings
# https://github.com/mtkennerly/dunamai/issues/114
.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
pre-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} git config --global user.email "example@pkgsrc.org"
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} git config --global user.name "pkgsrc test"

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
