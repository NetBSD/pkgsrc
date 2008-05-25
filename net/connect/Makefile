# $NetBSD: Makefile,v 1.10 2008/05/25 14:45:17 tron Exp $

DISTNAME=	connect
PKGNAME=	${DISTNAME}-1.95
CATEGORIES=	net security
MASTER_SITES=	http://zippo.taiyo.co.jp/~gotoh/ssh/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zippo.taiyo.co.jp/~gotoh/ssh/connect.html
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server

EXTRACT_ONLY=	# empty
DIST_SUBDIR=	${PKGNAME_NOREV}

LIBS.Darwin+=	-lresolv
LIBS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	bin

do-build:
	${MKDIR} ${WRKSRC}
	${LINK.c} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} -o ${WRKSRC}/connect ${LIBS}
	${EGREP} '^ \*(| .*)$$' ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | \
	${CUT} -c 4- >${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/connect
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
