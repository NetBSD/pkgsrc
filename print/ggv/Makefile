# $NetBSD: Makefile,v 1.10 2000/03/24 08:29:06 jlam Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
