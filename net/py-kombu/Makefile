# $NetBSD: Makefile,v 1.3 2014/01/02 04:49:16 dholland Exp $
#

DISTNAME=	kombu-3.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/k/kombu/
FETCH_USING=	curl

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://kombu.readthedocs.org/
COMMENT=	Messaging framework for Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 26
# py-amqp does not currently support py33; disable for now
#PYTHON_VERSIONS_ACCEPTED+=	33
REPLACE_PYTHON+=	kombu/tests/test_serialization.py

DEPENDS+=	${PYPKGPREFIX}-amqp>=1.3.3:../../net/py-amqp
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
