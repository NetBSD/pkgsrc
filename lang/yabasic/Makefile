# $NetBSD: Makefile,v 1.1.1.1 2003/05/02 23:19:53 jtb Exp $

DISTNAME=		yabasic-2.722
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@netbsd-fr.org
HOMEPAGE=		http://www.yabasic.de
COMMENT=		Yet another Basic for Unix and Windows

USE_X11=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/yabasic
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${PREFIX}/share/doc/html/yabasic

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
