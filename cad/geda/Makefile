# $NetBSD: Makefile,v 1.1.1.1 1998/11/24 21:11:58 tron Exp $
#

DISTNAME=	gEDA-19981117
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/dist/ \
		http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10
DEPENDS+=	guile-1.3:../../lang/guile

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_LIBTOOL=	yes

.include <../../mk/bsd.pkg.mk>
