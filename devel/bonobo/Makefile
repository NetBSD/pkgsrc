# $NetBSD: Makefile,v 1.46 2004/10/03 00:13:25 tv Exp $

DISTNAME=		bonobo-1.0.18
PKGREVISION=		8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo/1.0/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.libxml=	libxml>1.8.15

USE_BUILDLINK3=		YES
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

.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
