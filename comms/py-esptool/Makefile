# $NetBSD: Makefile,v 1.4 2019/08/13 16:44:27 gdt Exp $

DISTNAME=	esptool-2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}nb2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_PYPI:=e/esptool/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool/
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
