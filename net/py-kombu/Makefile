# $NetBSD: Makefile,v 1.5 2014/02/02 13:58:34 rodent Exp $

DISTNAME=	kombu-3.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/k/kombu/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://kombu.readthedocs.org/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-amqp>=1.4.1:../../net/py-amqp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
