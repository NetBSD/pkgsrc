# $NetBSD: Makefile,v 1.7 1999/10/22 23:41:45 tron Exp $
#

DISTNAME=       gnofin-0.6.0
CATEGORIES=	misc
MASTER_SITES=   ftp://jagger.berkeley.edu/pub/darin/gnofin/source/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://jagger.me.berkeley.edu/~dfisher/gnofin/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	esound-*:../../audio/esound
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
