# $NetBSD: Makefile,v 1.20 2018/06/16 06:22:01 adam Exp $

DISTNAME=	Faker-0.8.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Python package that generates fake data for you
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.2:../../textproc/py-text-unidecode

.include "../../lang/python/pyversion.mk"
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-ukpostcodeparser>=1.1.1:../../mail/py-ukpostcodeparser

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} faker faker${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
