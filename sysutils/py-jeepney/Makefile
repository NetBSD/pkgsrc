# $NetBSD: Makefile,v 1.2 2022/01/22 14:10:10 wiz Exp $

DISTNAME=	jeepney-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jeepney/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/takluyver/jeepney
COMMENT=	Low-level pure Python DBus protocol wrapper
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
