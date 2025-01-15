# $NetBSD: Makefile,v 1.93 2025/01/15 12:47:07 adam Exp $

DISTNAME=	faker-33.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Python package that generates fake data for you
LICENSE=	mit

WHEEL_NAME=	Faker-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-ukpostcodeparser>=1.1.1:../../mail/py-ukpostcodeparser
TEST_DEPENDS+=	${PYPKGPREFIX}-validators>=0.13.0:../../textproc/py-validators

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} faker faker-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
