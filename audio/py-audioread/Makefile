# $NetBSD: Makefile,v 1.15 2025/02/23 18:42:24 wiz Exp $

DISTNAME=	audioread-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/audioread/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sampsyo/audioread
COMMENT=	Audio file decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
