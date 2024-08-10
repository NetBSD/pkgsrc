# $NetBSD: Makefile,v 1.16 2024/08/10 16:15:57 wiz Exp $

VERSION=	2.1.0
# Bad distfile name reported upstream via email on 20240619.
DISTNAME=	paho_mqtt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-paho-mqtt-${VERSION}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paho-mqtt/}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	epl-v1.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling

# \todo Add support for running tests.
#TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.6.6:../../devel/py-lama
#TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
