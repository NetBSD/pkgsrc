# $NetBSD: Makefile,v 1.4 2014/01/26 08:46:00 wiz Exp $

DISTNAME=	kombu-3.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/k/kombu/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://kombu.readthedocs.org/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-amqp>=1.3.3:../../net/py-amqp

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	kombu/tests/test_serialization.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
