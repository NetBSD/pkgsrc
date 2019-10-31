# $NetBSD: Makefile,v 1.2 2019/10/31 00:32:16 gdt Exp $

DISTNAME=	paho-mqtt-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/59/11/1dd5c70f0f27a88a3a05772cd95f6087ac479fac66d9c7752ee5e16ddbbc/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	epl-v1.0

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.6.6:../../devel/py-lama
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
