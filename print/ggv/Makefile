# $NetBSD: Makefile,v 1.5 1999/08/29 12:48:59 rh Exp $
#

DISTNAME=	ggv-0.50
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ggv/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	ghostscript-5.50:../../print/ghostscript5
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core
DEPENDS+=	pth-1.1.3:../../devel/pth

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11=	YES

.include "../../mk/bsd.pkg.mk"
