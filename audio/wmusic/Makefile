# $NetBSD: Makefile,v 1.3 2003/05/02 11:53:47 wiz Exp $

DISTNAME=	wmusic-1.4.7
PKGREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://hadess.net/code.shtml
COMMENT=	WindowMaker dockable remote for xmms

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

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
