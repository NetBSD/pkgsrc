# $NetBSD: Makefile,v 1.5 2004/01/22 07:15:01 grant Exp $

DISTNAME=	wmusic-1.4.7
PKGREVISION=	2
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://hadess.net/code.shtml
COMMENT=	WindowMaker dockable remote for xmms

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmusic ${PREFIX}/bin
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} -d ${WRKSRC}/README ${PREFIX}/share/doc/wmusic
	@${INSTALL_DATA} -d ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmusic

.include "../../audio/xmms/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
