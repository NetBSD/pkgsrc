# $NetBSD: Makefile,v 1.11 1999/10/23 11:08:56 tron Exp $
#

DISTNAME=	gnumeric-0.38
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
