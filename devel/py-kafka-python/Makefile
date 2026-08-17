# $NetBSD: Makefile,v 1.6 2026/08/17 12:28:16 adam Exp $

DISTNAME=	kafka_python-3.0.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kafka-python/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/dpkp/kafka-python
COMMENT=	Pure Python client for Apache Kafka
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	kafka-python

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
