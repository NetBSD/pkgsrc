# $NetBSD: Makefile,v 1.28 2004/03/30 16:12:38 jmmv Exp $

DISTNAME=		dopewars-1.5.9
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dopewars/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://dopewars.sourceforge.net/
COMMENT=		Make a fortune dealing drugs on the streets of New York

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--disable-gui-client
CONFIGURE_ARGS+=	--disable-glib2
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--localstatedir=/var/games

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
