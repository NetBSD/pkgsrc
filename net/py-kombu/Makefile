# $NetBSD: Makefile,v 1.42 2026/11/26 08:44:29 adam Exp $

DISTNAME=	kombu-5.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kombu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kombu.readthedocs.io/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-amqp>=5.4.2:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-vine>=5.1.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-Pyro4>=0:../../devel/py-Pyro
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz>=0:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer>=0:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0:../../devel/py-test-sugar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
