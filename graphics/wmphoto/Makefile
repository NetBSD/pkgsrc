# $NetBSD: Makefile,v 1.21 2012/10/23 10:24:07 wiz Exp $
#

DISTNAME=	wmphoto-0.3a
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dcc.uchile.cl/~amartoq/wmphoto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dcc.uchile.cl/~amartoq/wmphoto/
COMMENT=	Dock-app that can show you a photo

BUILD_DIRS=	wmphoto
USE_X11BASE=	YES
USE_TOOLS+=	gmake
MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q} X11BASE=${X11BASE:Q}

INSTALLATION_DIRS+=	bin share/doc/wmphoto

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/HINTS \
	    ${DESTDIR}${PREFIX}/share/doc/wmphoto

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
