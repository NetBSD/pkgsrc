# $NetBSD: Makefile,v 1.10 1999/08/29 21:50:20 jlam Exp $
#

DISTNAME=	gEDA-19990516
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	guile-1.3.2:../../lang/guile

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
