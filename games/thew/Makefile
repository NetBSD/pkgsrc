# $NetBSD: Makefile,v 1.4 2012/10/06 11:54:56 asau Exp $

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
	${INSTALL_PROGRAM} ${WRKSRC}/thew ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thew.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
