# $NetBSD: Makefile,v 1.44 2004/02/14 18:26:27 jmmv Exp $
#

DISTNAME=		bonobo-1.0.18
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo/1.0/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.libxml=	libxml>1.8.15

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"
CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKGCONFIG_OVERRIDE=	libefs/libefs.pc.in

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
