# $NetBSD: Makefile,v 1.25 2002/04/08 12:42:35 mycroft Exp $
#

DISTNAME=	ggv-1.0.2
PKGREVISION=	1
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

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
