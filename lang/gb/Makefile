# $NetBSD: Makefile,v 1.8 2001/10/01 07:34:04 rh Exp $
#

DISTNAME=		gb-0.0.20
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gb/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gb/
COMMENT=		Basic for Gnome

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../print/gnome-print/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
