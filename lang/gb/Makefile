# $NetBSD: Makefile,v 1.26 2006/07/19 19:14:38 jlam Exp $
#

DISTNAME=		gb-0.0.20
PKGREVISION=		8
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gb/0.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gb/
COMMENT=		Basic for Gnome

GNU_CONFIGURE=		YES
USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

.include "../../print/gnome-print/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
