# $NetBSD: Makefile,v 1.3 1999/08/22 22:02:33 tron Exp $
#

DISTNAME=	gnumeric-0.31
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

DEPENDS+=	gnome-core-1.0.7:../../x11/gnome-core
DEPENDS+=	gnome-print-0.4:../../print/gnome-print
DEPENDS+=	libglade-0.2:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+= CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
