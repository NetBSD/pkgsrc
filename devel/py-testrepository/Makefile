# $NetBSD: Makefile,v 1.3 2022/01/27 10:57:32 wiz Exp $

DISTNAME=	testrepository-0.0.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/testrepository/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/testrepository
COMMENT=	Repository of test results
LICENSE=	apache-2.0 OR modified-bsd

DEPENDS+=	${PYPKGPREFIX}-fixtures-[0-9]*:../../devel/py-fixtures
DEPENDS+=	${PYPKGPREFIX}-subunit>=0.0.18:../../net/py-subunit
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-testresources-[0-9]*:../../devel/py-testresources
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios-[0-9]*:../../devel/py-testscenarios

PYTHON_VERSIONED_DEPENDENCIES+=	testtools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} testr testr-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
