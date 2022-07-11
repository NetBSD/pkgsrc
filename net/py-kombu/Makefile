# $NetBSD: Makefile,v 1.34 2022/07/11 08:43:01 adam Exp $

DISTNAME=	kombu-5.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kombu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kombu.readthedocs.io/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-amqp>=5.0.9:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-vine-[0-9]*:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=0.18:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-cached-property-[0-9]*:../../devel/py-cached-property
.endif

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
