# $NetBSD: Makefile,v 1.12 1999/11/07 22:19:27 tron Exp $

DISTNAME=	gnome-utils-1.0.50
CATEGORIES=	misc x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	ncurses-4.2:../../devel/ncurses
DEPENDS+=	gnome-core-*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ARGS=	--with-ncurses=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
