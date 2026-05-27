# $NetBSD: Makefile,v 1.2 2026/05/27 10:54:46 tm Exp $

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

CFLAGS.SunOS+=	-D__EXTENSIONS__        # getopt()
LDFLAGS.SunOS+=	-lsocket -lnsl -lresolv

pre-configure:
	${ECHO} prefix=${PREFIX} > ${WRKSRC}/config.mak

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
