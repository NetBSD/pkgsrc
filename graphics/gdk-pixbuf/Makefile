# $NetBSD: Makefile,v 1.4 2000/06/21 00:01:09 jlam Exp $
#

DISTNAME=		gdk-pixbuf-0.8.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gdk-pixbuf/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		gnome-libs>=1.0.53:../../x11/gnome-libs

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined

# our pkglibtool can't add a library to a library
#USE_LIBTOOL=		# defined
#LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
