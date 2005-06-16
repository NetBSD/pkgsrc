# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:40 jlam Exp $

DISTNAME=	wmusic-1.5.0
PKGREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://home.jtan.com/~john/wmusic/
COMMENT=	WindowMaker dockable remote for XMMS

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
