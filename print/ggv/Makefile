# $NetBSD: Makefile,v 1.32 2002/10/19 10:54:56 rh Exp $
#

DISTNAME=	ggv-1.0.2
PKGREVISION=	4
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ggv/1.0/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME frontend for GhostScript

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
BUILD_USES_MSGFMT=	YES
CONFIGURE_ARGS+=	--localstatedir=${X11PREFIX}/var/lib

.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
