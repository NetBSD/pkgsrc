# $NetBSD: Makefile,v 1.4 2023/01/16 13:08:43 vins Exp $

DISTNAME=	bsdfetch-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhx0/}
GITHUB_TAG=	644b1a54b7103307592c1ff67b3f9f641eaa437b

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/jhx0/bsdfetch/
COMMENT=	BSD system information tool written in C
LICENSE=	isc

ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdfetch ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
