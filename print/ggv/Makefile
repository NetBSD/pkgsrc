# $NetBSD: Makefile,v 1.28 2002/07/17 12:27:05 rh Exp $
#

DISTNAME=	ggv-1.0.2
PKGREVISION=	3
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME frontend for GhostScript

DEPENDS+=	ghostscript-[6-9]*:../../print/ghostscript

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
BUILD_USES_MSGFMT=	YES
CONFIGURE_ARGS+=	--localstatedir=${X11PREFIX}/var/lib

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
