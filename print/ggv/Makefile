# $NetBSD: Makefile,v 1.9 1999/10/23 11:08:58 tron Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
