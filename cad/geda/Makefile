# $NetBSD: Makefile,v 1.2 1998/12/31 12:05:52 frueauf Exp $
#

DISTNAME=	gEDA-19981213
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10
DEPENDS+=	guile-1.3:../../lang/guile

CONFLICTS=	gEDA-19981117

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
