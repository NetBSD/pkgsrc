# $NetBSD: Makefile,v 1.10 2001/03/27 03:19:50 hubertf Exp $
#

DISTNAME=		bonobo-0.30
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		ORBit>=0.5.6:../../net/ORBit
DEPENDS+=		gdk-pixbuf>=0.6.0:../../graphics/gdk-pixbuf
DEPENDS+=		oaf>=0.6.1:../../devel/oaf
DEPENDS+=		gnome-libs>=1.2.7:../../x11/gnome-libs
DEPENDS+=		gnome-print>=0.25:../../print/gnome-print

USE_LIBTOOL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
