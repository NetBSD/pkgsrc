# $NetBSD: Makefile,v 1.9 1999/09/10 15:39:34 rh Exp $
#

DISTNAME=	gnumeric-0.34
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=	${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core
DEPENDS+=	gnome-print-0.7:../../print/gnome-print
DEPENDS+=	libglade-0.5:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--without-bonobo

.include "../../mk/bsd.pkg.mk"
