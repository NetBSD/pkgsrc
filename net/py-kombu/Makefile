# $NetBSD: Makefile,v 1.38 2024/05/08 09:23:43 adam Exp $

DISTNAME=	kombu-5.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kombu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kombu.readthedocs.io/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-amqp>=5.1.1:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-vine-[0-9]*:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezer-[0-9]*:../../devel/py-test-freezer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
