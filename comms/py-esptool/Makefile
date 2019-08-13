# $NetBSD: Makefile,v 1.3 2019/08/13 12:03:55 gdt Exp $

GITHUB_PROJECT=	esptool
VERSION=	2.7
NBVERSION=	nb1
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${VERSION}${NBVERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GITHUB:=espressif/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/espressif/esptool/
COMMENT=	Firmware tool for ESP8266/ESP32
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}
EGG_INFODIR=	${GITHUB_PROJECT}-${VERSION}-py${PYVERSSUFFIX}.egg-info

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
