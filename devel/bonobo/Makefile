# $NetBSD: Makefile,v 1.18 2001/10/04 19:14:58 rh Exp $
#

DISTNAME=		bonobo-1.0.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.ORBit=ORBit>0.5.8

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/gdk-pixbuf-gnome/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
