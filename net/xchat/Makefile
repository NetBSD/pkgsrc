# $NetBSD: Makefile,v 1.6 1999/09/30 10:21:43 tron Exp $

DISTNAME=	xchat-1.2.1
CATEGORIES=	net x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/v1.2/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/

DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-configure:
	@cd ${WRKSRC} && ${LN} -fs myconfig.h config.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
