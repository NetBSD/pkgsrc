# $NetBSD: Makefile,v 1.4 2000/11/12 14:48:51 tron Exp $

DISTNAME=	gtm-0.4.5
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@bundy.lip.owl.de
HOMEPAGE=	http://gtm.sourceforge.net/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	wget-*:../../net/wget

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../mk/bsd.pkg.mk"
