# $NetBSD: Makefile,v 1.6 1999/08/29 22:07:19 rh Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
