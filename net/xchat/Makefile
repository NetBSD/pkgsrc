# $NetBSD: Makefile,v 1.10 2000/03/11 12:16:31 tron Exp $

DISTNAME=	xchat-1.4.1
CATEGORIES=	net x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/source/1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/

DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

#post-configure:
#	@cd ${WRKSRC} && ${LN} -fs myconfig.h config.h

post-install:
	${MKDIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
