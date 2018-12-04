# $NetBSD: Makefile,v 1.2 2018/12/04 12:54:01 adam Exp $

DISTNAME=	kafka-python-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kafka-python/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/dpkp/kafka-python
COMMENT=	Pure Python client for Apache Kafka
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
