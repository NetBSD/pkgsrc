# $NetBSD: Makefile,v 1.2 2001/09/27 23:17:49 jlam Exp $

DISTNAME=	tkirc2.46
PKGNAME=	tkirc2-2.46
CATEGORIES=	chat x11
MASTER_SITES=	ftp://ftp.netsplit.de/pub/tcltk/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netsplit.de/tkirc2/
COMMENT=	GUI for the ircII Internet Relay Chat client

DEPENDS+=	ircII-[0-9]*:../../chat/ircII
DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tkirc2

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc2 ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkirc2
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tkirc2/scripts
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tkirc2
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/tkirc2
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/tkirc2
	${INSTALL_SCRIPT} ${WRKSRC}/.tkirc2/scripts/* \
	  ${PREFIX}/share/examples/tkirc2/scripts
	${INSTALL_DATA} ${WRKSRC}/.tkirc2/netscape.sh \
	  ${PREFIX}/share/examples/tkirc2
	${INSTALL_DATA} ${WRKSRC}/.tkirc2/tkircrc-example \
	   ${PREFIX}/share/examples/tkirc2

.include "../../mk/bsd.pkg.mk"
