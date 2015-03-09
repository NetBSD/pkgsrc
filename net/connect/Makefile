# $NetBSD: Makefile,v 1.17 2015/03/09 09:24:35 mef Exp $

DISTNAME=	1.104
PKGNAME=	connect-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=   http://bitbucket.org/gotoh/connect/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/gotoh/connect/wiki/Home
COMMENT=	Open a TCP connection using a SOCKS4/5 or HTTP proxy server
LICENSE=	gnu-gpl-v2

CONFLICTS=	azara-[0-9]*

DIST_SUBDIR=	${PKGBASE}
WRKSRC=		${WRKDIR}/gotoh-${PKGNAME_NOREV}
USE_TOOLS=	gmake

LIBS.Darwin+=	-lresolv
LIBS.SunOS+=	-lresolv -lsocket -lnsl

INSTALLATION_DIRS=	bin share/doc/connect

pre-patch:
	(cd ${WRKDIR}; ${MV} gotoh-connect-* gotoh-${PKGNAME_NOREV})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/connect ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${DESTDIR}${PREFIX}/share/doc/connect
	${INSTALL_DATA} ${WRKSRC}/doc/manual.txt ${DESTDIR}${PREFIX}/share/doc/connect

.include "../../mk/bsd.pkg.mk"
