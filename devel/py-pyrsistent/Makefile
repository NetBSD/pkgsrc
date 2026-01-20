# $NetBSD: Makefile,v 1.15 2026/01/20 08:19:46 wiz Exp $

DISTNAME=	pyrsistent-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrsistent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tobgu/pyrsistent
COMMENT=	Persistent/Functional/Immutable data structures
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-int-conversion

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
