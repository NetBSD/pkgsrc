# $NetBSD: Makefile,v 1.33 2019/11/14 10:42:38 adam Exp $

DISTNAME=	Faker-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Python package that generates fake data for you
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.2:../../textproc/py-text-unidecode
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-ukpostcodeparser>=1.1.1:../../mail/py-ukpostcodeparser
TEST_DEPENDS+=	${PYPKGPREFIX}-validators>=0.13.0:../../textproc/py-validators
# not packaged
#TEST_DEPENDS+=	${PYPKGPREFIX}-random2

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} faker faker-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
