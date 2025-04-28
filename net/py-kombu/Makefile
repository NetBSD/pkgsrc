# $NetBSD: Makefile,v 1.41 2025/04/28 20:37:36 adam Exp $

DISTNAME=	kombu-5.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kombu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kombu.readthedocs.io/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-amqp>=5.1.1:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2025.2:../../time/py-tzdata
DEPENDS+=	${PYPKGPREFIX}-vine>=5.1.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer-[0-9]*:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
