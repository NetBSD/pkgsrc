# $NetBSD: Makefile,v 1.6 1999/03/01 13:16:24 rh Exp $
#

DISTNAME=	gEDA-19990226
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
