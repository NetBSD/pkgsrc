# $NetBSD: Makefile,v 1.10 1999/01/29 19:24:13 tron Exp $

DISTNAME=	tkirc1.202
PKGNAME=	tkirc-1.202
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.north.de/~atte/tkirc/

DEPENDS+=	ircII-4.4:../../net/ircII
DEPENDS+=	tk-8.0p2:../../x11/tk80

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/tkirc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING	  ${PREFIX}/share/doc/tkirc

.include "../../mk/bsd.pkg.mk"
