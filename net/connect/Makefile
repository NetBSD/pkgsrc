# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:24 jlam Exp $

DISTNAME=	connect
PKGNAME=	${DISTNAME}-1.83
CATEGORIES=	net security
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.c

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.imasy.or.jp/~gotoh/ssh/
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server

EXTRACT_ONLY=	# empty
DIST_SUBDIR=	${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
LIBS=	-lresolv
.elif ${OPSYS} == SunOS
LIBS=	-lsocket -lnsl
.else
LIBS=
.endif

INSTALLATION_DIRS=	bin

do-build:
	${MKDIR} ${WRKSRC}
	${CC} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${CFLAGS} -o ${WRKSRC}/connect ${LIBS}
	${EGREP} '^ \*(| .*)$$' ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	${CUT} -c 4- >${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/connect
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
