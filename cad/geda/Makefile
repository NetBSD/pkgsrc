# $NetBSD: Makefile,v 1.7 1999/03/28 21:22:23 rh Exp $
#

DISTNAME=	gEDA-19990327
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk10-1.0.6:../../x11/gtk10
DEPENDS+=	guile-1.3:../../lang/guile

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gtk-config=${X11BASE}/bin/gtk10-config

.include "../../mk/bsd.pkg.mk"
