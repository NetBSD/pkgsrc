# $NetBSD: Makefile,v 1.1.1.1 2002/06/19 13:06:01 agc Exp $

DISTNAME=	wmusic-1.4.7
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://hadess.net/code.shtml
COMMENT=	WindowMaker dockable remote for xmms

USE_BUILDLINK_ONLY=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} -d ${WRKSRC}/README ${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} -d ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
