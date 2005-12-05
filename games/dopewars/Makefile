# $NetBSD: Makefile,v 1.35 2005/12/05 20:50:15 rillig Exp $

DISTNAME=	dopewars-1.5.10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dopewars/}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://dopewars.sourceforge.net/
COMMENT=	Make a fortune dealing drugs on the streets of New York

USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--disable-gui-client
CONFIGURE_ARGS+=	--disable-glib2
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*-*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
