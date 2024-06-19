# $NetBSD: Makefile,v 1.14 2024/06/19 14:03:04 gdt Exp $

VERSION=	2.1.0
# Bad distfile name reported upstream via email on 20240619.
DISTNAME=	paho_mqtt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-paho-mqtt-${VERSION}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paho-mqtt/}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	epl-v1.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling

# \todo Add support for running tests.
#TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
#TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.6.6:../../devel/py-lama
#TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
