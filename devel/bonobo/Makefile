# $NetBSD: Makefile,v 1.34.2.1 2003/02/17 04:44:02 agc Exp $
#

DISTNAME=		bonobo-1.0.18
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo/1.0/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.libxml=	libxml>1.8.15

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
CONFIGURE_ARGS+=	--enable-gtk-doc=no

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/libefs/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libefs/libefs.pc.in

post-install:
	-@${RMDIR} ${PREFIX}/share/libefs/html/libefs
	-@${RMDIR} ${PREFIX}/share/libefs/html
	-@${RMDIR} ${PREFIX}/share/libefs

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
