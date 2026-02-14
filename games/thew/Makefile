# $NetBSD: Makefile,v 1.7 2026/02/14 08:16:16 wiz Exp $

DISTNAME=		thew-1.1.1
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=thew/}
MASTER_SITES+=		http://dinotte.altervista.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ilfoglionascosto@netcat.it
HOMEPAGE=		https://thew.sourceforge.net/
COMMENT=		The hermit worm

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thew ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thew.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
