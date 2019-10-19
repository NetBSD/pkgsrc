# $NetBSD: Makefile,v 1.2 2019/10/19 14:29:45 adam Exp $

DISTNAME=	pyrsistent-0.15.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyrsistent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tobgu/pyrsistent
COMMENT=	Persistent/Functional/Immutable data structures
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
