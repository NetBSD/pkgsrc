# $NetBSD: Makefile,v 1.28 2002/09/21 08:48:39 jlam Exp $
#

DISTNAME=		bonobo-1.0.18
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/bonobo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Architecture for creating reusable software components

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

BUILDLINK_DEPENDS.libxml=	libxml>1.8.15

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=		X11BASE="${X11BASE}"

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/gdk-pixbuf-gnome/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
