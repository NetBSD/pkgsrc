# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:53 jmmv Exp $
#

DISTNAME=	6tunnel-0.09
WRKSRC=		${WRKDIR}/6tunnel
CATEGORIES=	net
MASTER_SITES=	ftp://amba.bydg.pdi.net/pub/wojtekka/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	v4/v6 protocol translation

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
