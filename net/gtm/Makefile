# $NetBSD: Makefile,v 1.2 2000/09/17 21:48:23 tron Exp $

DISTNAME=	gtm-0.4.5
CATEGORIES=	net gnome
MASTER_SITES=	http://download.sourceforge.net/gtm/

MAINTAINER=	magick@bundy.lip.owl.de
HOMEPAGE=	http://gtm.sourceforge.net/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	wget-*:../../net/wget

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../mk/bsd.pkg.mk"
