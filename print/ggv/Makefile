# $NetBSD: Makefile,v 1.24 2002/03/23 06:43:53 uebayasi Exp $
#

DISTNAME=	ggv-1.0.2
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
