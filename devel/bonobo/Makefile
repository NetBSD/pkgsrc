# $NetBSD: Makefile,v 1.5 2000/08/29 16:28:41 rh Exp $
#

DISTNAME=		bonobo-0.18
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=/unstable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=		gdk-pixbuf>=0.6.0:../../graphics/gdk-pixbuf
DEPENDS+=		oaf>=0.5.0:../../devel/oaf
DEPENDS+=		gnome-print>=0.16:../../print/gnome-print

USE_LIBTOOL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
