# $NetBSD: Makefile,v 1.10 2002/10/08 12:23:12 wiz Exp $
#

DISTNAME=		gb-0.0.20
PKGREVISION=		1
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gb/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/gb/
COMMENT=		Basic for Gnome

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../print/gnome-print/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
