# $NetBSD: Makefile,v 1.9 2001/09/27 23:18:27 jlam Exp $

DISTNAME=	gtm-0.4.9
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://gtm.sourceforge.net/
COMMENT=	Gnome Transfer Manager

DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core
DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

post-install:
	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../mk/bsd.pkg.mk"
