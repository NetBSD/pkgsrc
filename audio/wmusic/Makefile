# $NetBSD: Makefile,v 1.9 2004/09/01 15:00:59 reed Exp $

DISTNAME=	wmusic-1.5.0
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://home.jtan.com/~john/wmusic/

MAINTAINER=	joel@carnat.net
HOMEPAGE=	http://home.jtan.com/~john/wmusic/
COMMENT=	WindowMaker dockable remote for XMMS

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmusic
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
