# $NetBSD: Makefile,v 1.2 2007/12/07 05:28:30 rillig Exp $

DISTNAME=		thew-1.1.1
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=thew/} \
			http://dinotte.altervista.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ilfoglionascosto@netcat.it
HOMEPAGE=		http://thew.sourceforce.net/
COMMENT=		The hermit worm

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thew ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thew.6 ${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
