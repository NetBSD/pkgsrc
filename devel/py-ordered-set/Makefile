# $NetBSD: Makefile,v 1.3 2018/07/13 06:24:25 adam Exp $

DISTNAME=	ordered-set-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/ordered-set/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LuminosoInsight/ordered-set
COMMENT=	MutableSet that remembers its order
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
