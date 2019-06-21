# $NetBSD: Makefile,v 1.23 2019/06/21 11:25:00 adam Exp $

DISTNAME=	kombu-4.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kombu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kombu.readthedocs.org/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-amqp>=2.5.0:../../net/py-amqp
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-Pyro-[0-9]*:../../devel/py-Pyro
TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.5.2:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
