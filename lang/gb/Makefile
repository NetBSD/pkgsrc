# $NetBSD: Makefile,v 1.20 2004/04/28 05:06:28 snj Exp $
#

DISTNAME=		gb-0.0.20
PKGREVISION=		5
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gb/0.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gb/
COMMENT=		Basic for Gnome

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../print/gnome-print/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
