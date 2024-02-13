# $NetBSD: Makefile,v 1.13 2024/02/13 19:38:38 gdt Exp $

# Update to 2.0.0 is on hold, until after 2024Q1.  It has an API break
# requiring modification of all users, and those users are just now
# coping with making those changes (e.g. weewx extensions).
DISTNAME=	paho-mqtt-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/paho-mqtt/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.eclipse.org/paho/
COMMENT=	MQTT version 3.1.1 client class
LICENSE=	epl-v1.0

# tests are not included
#TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
#TEST_DEPENDS+=	${PYPKGPREFIX}-lama>=7.6.6:../../devel/py-lama
#TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
