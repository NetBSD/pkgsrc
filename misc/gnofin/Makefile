# $NetBSD: Makefile,v 1.5 1999/09/03 07:22:55 rh Exp $
#

DISTNAME=       gnofin-0.6.0
CATEGORIES=	misc
MASTER_SITES=   ftp://jagger.berkeley.edu/pub/darin/gnofin/source/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://jagger.me.berkeley.edu/~dfisher/gnofin/

DEPENDS+=	glib-1.2.4:../../devel/glib
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	gnome-libs-1.0.16:../../x11/gnome-libs

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
