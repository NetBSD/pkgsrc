# $NetBSD: Makefile,v 1.1.1.1 2002/07/12 17:15:54 wiz Exp $
#

DISTNAME=		libgnomeprint-1.115.0
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/libgnomeprint/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Library for the GNOME2 Printing Architecture

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES

pre-configure:
	${MV} ${WRKSRC}/installer/README.installer ${WRKSRC}/installer/README.installer.2

.include "../../devel/libbonobo/buildlink.mk"
.include "../../devel/pango/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/libart2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
