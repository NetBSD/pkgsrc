# $NetBSD: Makefile,v 1.6 2004/03/07 21:30:12 snj Exp $

DISTNAME=	wmusic-1.4.7
PKGREVISION=	2
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/attic/wmusic/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://hadess.net/code.shtml
COMMENT=	WindowMaker dockable remote for xmms

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
