# $NetBSD: Makefile,v 1.11 1999/10/24 16:43:08 tron Exp $
#

DISTNAME=	gEDA-19990516
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	guile-1.3.2:../../lang/guile

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
