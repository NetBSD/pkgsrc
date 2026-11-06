# $NetBSD: Makefile,v 1.17 2026/11/06 01:08:53 gdt Exp $

VERSION=	2.2.0
# Bad distfile name reported upstream via email on 20240619.
# Still wrong 20261105.
DISTNAME=	paho_mqtt-${VERSION}
PKGNAME=	${PYPKGPREFIX}-paho-mqtt-${VERSION}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paho-mqtt/}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/paho/
COMMENT=	MQTT client Python library
LICENSE=	epl-v1.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling

# Optional dependency omitted: PySocks

# \todo Resolve test issues.

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
