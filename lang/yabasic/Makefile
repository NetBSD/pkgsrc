# $NetBSD: Makefile,v 1.7 2004/10/03 00:15:03 tv Exp $

DISTNAME=		yabasic-2.722
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@netbsd-fr.org
HOMEPAGE=		http://www.yabasic.de/
COMMENT=		Yet another Basic for Unix and Windows

USE_X11=		YES
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/yabasic
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${PREFIX}/share/doc/html/yabasic

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
