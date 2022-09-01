# $NetBSD: Makefile,v 1.61 2022/09/01 07:24:08 adam Exp $

DISTNAME=	Faker-14.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Python package that generates fake data for you
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-random2-[0-9]*:../../devel/py-random2
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-ukpostcodeparser>=1.1.1:../../mail/py-ukpostcodeparser
TEST_DEPENDS+=	${PYPKGPREFIX}-validators>=0.13.0:../../textproc/py-validators

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 4.0.0

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.2:../../devel/py-typing-extensions
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} faker faker-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
