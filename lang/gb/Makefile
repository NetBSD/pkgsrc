# $NetBSD: Makefile,v 1.12 2002/12/01 15:02:08 salo Exp $
#

DISTNAME=		gb-0.0.20
PKGREVISION=		1
CATEGORIES=		lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gb/0.0/}

MAINTAINER=		rh@netbsd.org
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
.include "../../mk/bsd.pkg.mk"
