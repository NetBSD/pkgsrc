# $NetBSD: Makefile,v 1.6 2025/09/30 16:07:39 wiz Exp $

DISTNAME=	bsdfetch-1.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jhx0/}
GITHUB_TAG=	e0b77bfb2ea7adad197eb392c8a64536bd9315e4

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
	${INSTALL_PROGRAM} ${WRKSRC}/bsdfetch ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
