# $NetBSD: Makefile,v 1.17 2004/10/03 00:18:00 tv Exp $

DISTNAME=	trafshow-4.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.nsk.su/pub/RinetSoftware/
EXTRACT_SUFX=	.tgz

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://soft.risp.ru/trafshow/index.shtml
COMMENT=	Full screen visualization of the network traffic

ALL_TARGET=	trafshow
GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
CPPFLAGS+=	-DINET6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trafshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/trafshow.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/trafshow
	${INSTALL_DATA} ${WRKSRC}/.trafshow \
		${PREFIX}/share/examples/trafshow/trafshow

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
