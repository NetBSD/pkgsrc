# $NetBSD: Makefile,v 1.7 2020/05/16 16:35:24 adam Exp $

DISTNAME=	pyrsistent-0.16.0
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
