# $NetBSD: Makefile,v 1.4 2000/07/16 19:50:12 rh Exp $
#

DISTNAME=		bonobo-0.15
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=/unstable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=		gdk-pixbuf-*:../../graphics/gdk-pixbuf
DEPENDS+=		oaf-*:../../devel/oaf
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
