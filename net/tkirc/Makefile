# New ports collection makefile for:    tkirc
# Version required:     1.202
# Date created:         1997/11/09
# Whom:                 Hubert Feyrer <hubertf@netbsd.org>
#
# $NetBSD: Makefile,v 1.5 1998/03/28 21:41:11 tron Exp $

DISTNAME=	tkirc1.202
PKGNAME=	tkirc-1.202
CATEGORIES=	net x11
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/

MAINTAINER=	hubertf@netbsd.org

RUN_DEPENDS=	irc:${PORTSDIR}/net/ircII \
		wish8.0:${PORTSDIR}/x11/tk80

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

.include <bsd.port.mk>
