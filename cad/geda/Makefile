# $NetBSD: Makefile,v 1.4 1999/02/04 21:21:23 frueauf Exp $
#

DISTNAME=	gEDA-19990124
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10
DEPENDS+=	guile-1.3:../../lang/guile

CONFLICTS=	gEDA-*

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
