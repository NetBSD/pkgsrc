# $NetBSD: Makefile,v 1.14 1999/11/17 10:54:03 rh Exp $
#

DISTNAME=	gnumeric-0.41
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnumeric/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=	${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	gnome-print-*:../../print/gnome-print
DEPENDS+=	libglade-*:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--without-bonobo

.include "../../mk/bsd.pkg.mk"
