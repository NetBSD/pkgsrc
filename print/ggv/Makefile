# $NetBSD: Makefile,v 1.27 2002/05/31 00:26:10 dmcmahill Exp $
#

DISTNAME=	ggv-1.0.2
PKGREVISION=	2
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

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
