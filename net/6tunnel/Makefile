# $NetBSD: Makefile,v 1.2 2001/10/23 20:23:09 zuntum Exp $
#

DISTNAME=	6tunnel-0.09
CATEGORIES=	net
MASTER_SITES=	ftp://amba.bydg.pdi.net/pub/wojtekka/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	v4/v6 protocol translation

WRKSRC=		${WRKDIR}/6tunnel

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
