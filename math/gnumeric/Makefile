# $NetBSD: Makefile,v 1.15 2000/01/01 14:23:24 rh Exp $
#

DISTNAME=	gnumeric-0.46
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnumeric/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/gnumeric/

BUILD_DEPENDS+=	${LOCALBASE}/bin/python:../../lang/python
DEPENDS+=	gnome-core-*:../../x11/gnome-core
DEPENDS+=	gnome-print-*:../../print/gnome-print
DEPENDS+=	libglade>=0.11:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_PERL5=	YES
LDFLAGS+=       -L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--without-bonobo

.include "../../mk/bsd.pkg.mk"
