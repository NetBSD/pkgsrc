# $NetBSD: Makefile,v 1.2 2000/05/30 19:30:22 drochner Exp $
#

DISTNAME=	gdk-pixbuf-0.8.0
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gdk-pixbuf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gnome-libs>=1.0.53:../../x11/gnome-libs

GNU_CONFIGURE=	YES
#our pkglibtool can't add a library to a library
#USE_LIBTOOL=	YES
USE_X11BASE=	YES
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=	X11BASE="${X11BASE}"
LDFLAGS+=	"-L${LOCALBASE}/lib"

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
