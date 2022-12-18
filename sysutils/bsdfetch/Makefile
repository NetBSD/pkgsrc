# $NetBSD: Makefile,v 1.1 2022/12/18 14:30:56 vins Exp $

DISTNAME=	bsdfetch-1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhx0/}
GITHUB_TAG=	e2c091320656a34aedc39f50dca9a629a39b00da

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/jhx0/bsdfetch/
COMMENT=	BSD system information tool written in C
LICENSE=	isc

ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-*

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdfetch ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
