# $NetBSD: Makefile,v 1.20 2026/06/12 10:27:57 adam Exp $

DISTNAME=	sh-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/amoffat/sh
COMMENT=	Python subprocess replacement
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/sh_test.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
