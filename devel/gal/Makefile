# $NetBSD: Makefile,v 1.3 2000/11/06 18:15:33 rh Exp $
#

DISTNAME=	gal-0.2.1
CATEGORIES=	gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gal/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	gnome-print>=0.24:../../print/gnome-print
DEPENDS+=	libglade>=0.14:../../devel/libglade

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
