# $NetBSD: Makefile,v 1.13 1999/10/23 11:08:57 tron Exp $
#

DISTNAME=	gnome-pim-1.0.50
CATEGORIES=	misc x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-pim/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
