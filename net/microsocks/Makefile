# $NetBSD: Makefile,v 1.1 2026/01/21 18:26:43 gdt Exp $

DISTNAME=	microsocks-1.0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rofl0r/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/rofl0r/microsocks/
COMMENT=	Multithreaded, small, efficient SOCKS5 server
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99

pre-configure:
	${ECHO} prefix=${PREFIX} > ${WRKSRC}/config.mak

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
