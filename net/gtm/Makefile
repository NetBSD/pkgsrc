# $NetBSD: Makefile,v 1.6 2001/03/13 16:33:42 wiz Exp $

DISTNAME=	gtm-0.4.6
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@zhadum.de
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
