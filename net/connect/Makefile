# $NetBSD: Makefile,v 1.14 2012/10/23 17:18:15 asau Exp $

DISTNAME=	connect
PKGNAME=	${DISTNAME}-1.95
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://zippo.taiyo.co.jp/~gotoh/ssh/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zippo.taiyo.co.jp/~gotoh/ssh/connect.html
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server
LICENSE=	gnu-gpl-v2

CONFLICTS=	azara-[0-9]*

EXTRACT_ONLY=	# empty
DIST_SUBDIR=	${PKGNAME_NOREV}

LIBS.Darwin+=	-lresolv
LIBS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	bin share/doc/connect

do-build:
	${MKDIR} ${WRKSRC}
	${LINK.c} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES:Q} -o ${WRKSRC}/connect ${LIBS}
	${EGREP} '^ \*(| .*)$$' ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES:Q} | \
	${CUT} -c 4- >${WRKSRC}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
