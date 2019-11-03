# $NetBSD: Makefile,v 1.5 2019/11/03 10:18:27 rillig Exp $

DISTNAME=	extras-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=e/extras/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/extras
COMMENT=	Useful extra bits for Python
LICENSE=	mit

USE_LANGUAGES=	# none

# TEST_DEPENDS
BUILD_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# testtools depends on extras
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
