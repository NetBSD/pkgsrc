# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:18 agc Exp $
#

DISTNAME=	6tunnel-0.09
CATEGORIES=	net
MASTER_SITES=	ftp://amba.bydg.pdi.net/pub/wojtekka/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	v4/v6 protocol translation

WRKSRC=		${WRKDIR}/6tunnel

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
.endif

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
