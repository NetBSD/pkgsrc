# $NetBSD: Makefile,v 1.4 2003/09/28 09:13:57 jlam Exp $

DISTNAME=		yabasic-2.722
PKGREVISION=		1
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
