# $NetBSD: Makefile,v 1.121 2026/09/03 11:18:40 adam Exp $

DISTNAME=	faker-40.38.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Faker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joke2k/faker
COMMENT=	Python package that generates fake data for you
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# tzdata
DEPENDS+=	${PYPKGPREFIX}-tzdata>=0:../../time/py-tzdata
TEST_DEPENDS+=	${PYPKGPREFIX}-email_validator>=1.0.0:../../mail/py-email_validator
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-ukpostcodeparser>=1.1.1:../../mail/py-ukpostcodeparser
TEST_DEPENDS+=	${PYPKGPREFIX}-validators>=0.13.0:../../textproc/py-validators

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	faker

# as of 40.4.0
# 341 passed, 10 skipped, 13 warnings, 1858 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
