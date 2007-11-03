# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 18:14:20 rillig Exp $

DISTNAME=		thew-1.1.1
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=thew/} \
			http://dinotte.altervista.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ilfoglionascosto@netcat.it
HOMEPAGE=		http://thew.sourceforce.net/
COMMENT=		The hermit worm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thew ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thew.6 ${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
