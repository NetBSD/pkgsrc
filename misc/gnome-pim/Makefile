# $NetBSD: Makefile,v 1.10 1999/08/29 12:48:59 rh Exp $
#

DISTNAME=	gnome-pim-1.0.8
CATEGORIES=	misc x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
