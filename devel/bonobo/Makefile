# $NetBSD: Makefile,v 1.2 2000/05/12 14:17:29 tron Exp $
#

DISTNAME=		bonobo-0.4
CATEGORIES=		devel
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
