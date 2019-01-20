# $NetBSD: Makefile,v 1.3 2019/01/20 17:39:05 wiz Exp $

GITHUB_PROJECT=	arm-trusted-firmware
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	arm-trusted-firmware-2.0
PKGNAME=	${DISTNAME:S/firmware/firmware-fiptool/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ARM-software/}
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/ARM-software/arm-trusted-firmware/
COMMENT=	ARM Trusted Firmware fiptool
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/tools/fiptool

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiptool ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
