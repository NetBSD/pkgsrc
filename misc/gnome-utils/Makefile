# $NetBSD: Makefile,v 1.21 2000/06/24 16:44:01 danw Exp $

DISTNAME=	gnome-utils-1.2.0
CATEGORIES=	misc x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-utils/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	libgtop>=1.0.9:../../devel/libgtop

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ARGS=	--with-ncurses=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
