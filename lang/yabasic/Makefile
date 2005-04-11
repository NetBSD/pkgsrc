# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:17 tv Exp $

DISTNAME=		yabasic-2.722
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@netbsd-fr.org
HOMEPAGE=		http://www.yabasic.de/
COMMENT=		Yet another Basic for Unix and Windows

USE_X11=		YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/yabasic
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${PREFIX}/share/doc/html/yabasic

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
