# $NetBSD: Makefile,v 1.1.1.1 2000/12/11 13:53:26 wiz Exp $
#

DISTNAME=       emma-0.7-5
PKGNAME=	emma-0.7.5
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	finance
MASTER_SITES=   http://rainbow.mimuw.edu.pl/~la181249/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	python-*:../../lang/python

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
