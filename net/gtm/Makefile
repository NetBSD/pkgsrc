# $NetBSD: Makefile,v 1.5 2001/02/17 18:18:57 wiz Exp $

DISTNAME=	gtm-0.4.5
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@bundy.lip.owl.de
HOMEPAGE=	http://gtm.sourceforge.net/
COMMENT=	Gnome Transfer Manager

DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	wget-*:../../net/wget

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../mk/bsd.pkg.mk"
