# $NetBSD: Makefile,v 1.3 1999/08/29 12:48:59 rh Exp $

DISTNAME=	xchat-1.0.0
CATEGORIES=	net x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.linuxpower.org/

DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	${MKDIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
