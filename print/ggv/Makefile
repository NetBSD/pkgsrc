# $NetBSD: Makefile,v 1.29 2002/09/10 16:06:48 wiz Exp $
#

DISTNAME=	ggv-1.0.2
PKGREVISION=	4
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
