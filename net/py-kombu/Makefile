# $NetBSD: Makefile,v 1.10 2014/06/09 00:16:23 rodent Exp $

DISTNAME=	kombu-3.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/k/kombu/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://kombu.readthedocs.org/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-anyjson>=0.3.3:../../textproc/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-amqp>=1.4.5<2.0:../../net/py-amqp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
