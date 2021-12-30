# $NetBSD: Makefile,v 1.4 2021/12/30 12:06:00 adam Exp $

DISTNAME=	eliot-1.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eliot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/itamarst/eliot
COMMENT=	Logging library that tells you why it happened
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-boltons>=19.0.1:../../devel/py-boltons
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.11.8:../../devel/py-pyrsistent
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=1.14.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} eliot-prettyprint eliot-prettyprint-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} eliot/tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
