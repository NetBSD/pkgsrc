# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 15:15:16 rh Exp $
#

DISTNAME=		bonobo-0.4
CATEGORIES=		devel corba
MASTER_SITES=		${MASTER_SITE_GNOME:=/unstable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/

DEPENDS+=		bison-*:../../devel/bison
DEPENDS+=		gdk-pixbuf-*:../../graphics/gdk-pixbuf

USE_LIBTOOL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
LDFLAGS+=		"-L${LOCALBASE}/lib"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
