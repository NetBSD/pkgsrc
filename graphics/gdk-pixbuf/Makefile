# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 15:08:16 rh Exp $
#

DISTNAME=	gdk-pixbuf-0.4
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gdk-pixbuf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs>=1.0.53:../../x11/gnome-libs

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=	X11BASE="${X11BASE}"
LDFLAGS+=	"-L${LOCALBASE}/lib"

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
