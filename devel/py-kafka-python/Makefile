# $NetBSD: Makefile,v 1.3 2022/01/04 20:53:14 wiz Exp $

DISTNAME=	kafka-python-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
