# $NetBSD: Makefile,v 1.16 2001/08/11 18:26:56 rh Exp $
#

DISTNAME=		bonobo-1.0.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		ORBit>=0.5.8:../../net/ORBit
DEPENDS+=		gdk-pixbuf-gnome>=0.10.0:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		oaf>=0.6.5:../../devel/oaf
DEPENDS+=		gnome-libs>=1.2.13:../../x11/gnome-libs
DEPENDS+=		gnome-print>=0.28:../../print/gnome-print

USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
