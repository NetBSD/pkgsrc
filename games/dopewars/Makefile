# $NetBSD: Makefile,v 1.20 2003/09/27 17:07:36 grant Exp $

DISTNAME=		dopewars-1.5.9
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/ \
			${MASTER_SITE_SOURCEFORGE:=dopewars/} \
			http://berlin.sfai.edu/~tobi/dopewars/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/
COMMENT=		Make a fortune dealing drugs on the streets of New York

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--disable-gui-client
CONFIGURE_ARGS+=	--disable-glib2
CONFIGURE_ARGS+=	--without-esd
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--localstatedir=/var/games

USE_NCURSES=		# KEY_RESIZE

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
