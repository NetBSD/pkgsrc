# $NetBSD: Makefile,v 1.2 2019/11/03 10:18:29 rillig Exp $

DISTNAME=	testresources-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testresources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/testresources
COMMENT=	Pyunit extension for managing expensive test resources
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=		${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
DEPENDS+=		${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
# TEST_DEPENDS
BUILD_DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
# circular dependency
#BUILD_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
