# $NetBSD: Makefile,v 1.3 2008/03/04 06:59:06 jlam Exp $

DISTNAME=		thew-1.1.1
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=thew/} \
			http://dinotte.altervista.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ilfoglionascosto@netcat.it
HOMEPAGE=		http://thew.sourceforce.net/
COMMENT=		The hermit worm

PKG_DESTDIR_SUPPORT=	user-destdir
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thew ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thew.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
