# $NetBSD: Makefile,v 1.1.1.1 2004/01/15 19:11:17 tron Exp $

DISTNAME=	connect
PKGNAME=	${DISTNAME}-1.69
CATEGORIES=	net security
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.c

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~gotoh/ssh/
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server

EXTRACT_ONLY=	# empty

do-build:
	${MKDIR} ${WRKSRC}
	${CC} ${DISTDIR}/${DISTFILES} ${CFLAGS} -o ${WRKSRC}/connect
	${EGREP} '^ \*(| .*)$$' ${DISTDIR}/${DISTFILES} | \
	${CUT} -c 4- >${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/connect
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
