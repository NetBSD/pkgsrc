# $NetBSD: Makefile,v 1.5 2015/08/18 07:31:09 wiz Exp $

DISTNAME=		thew-1.1.1
PKGREVISION=		3
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
