# $NetBSD: Makefile,v 1.18 2003/07/17 21:44:22 grant Exp $
#

DISTNAME=		gb-0.0.20
PKGREVISION=		4
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gb/0.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/gb/
COMMENT=		Basic for Gnome

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../print/gnome-print/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
