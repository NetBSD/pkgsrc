# $NetBSD: Makefile,v 1.13 2001/04/27 19:44:39 danw Exp $
#

DISTNAME=		bonobo-1.0.2
PKGNAME=		bonobo-1.0.2nb1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		ORBit>=0.5.7:../../net/ORBit
DEPENDS+=		gdk-pixbuf-gnome>=0.10.0:../../graphics/gdk-pixbuf-gnome
DEPENDS+=		oaf>=0.6.5:../../devel/oaf
DEPENDS+=		gnome-libs>=1.2.13:../../x11/gnome-libs
DEPENDS+=		gnome-print>=0.28:../../print/gnome-print

USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
