# $NetBSD: Makefile,v 1.10 2005/06/01 18:02:59 jlam Exp $

DISTNAME=		yabasic-2.722
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@silicium.ath.cx
HOMEPAGE=		http://www.yabasic.de/
COMMENT=		Yet another Basic for Unix and Windows

GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/yabasic
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${PREFIX}/share/doc/html/yabasic

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
