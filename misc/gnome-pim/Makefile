# $NetBSD: Makefile,v 1.12 1999/10/09 21:14:03 rh Exp $
#

DISTNAME=	gnome-pim-1.0.50
CATEGORIES=	misc x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-pim/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
