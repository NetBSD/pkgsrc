# $NetBSD: Makefile,v 1.6 2001/06/04 16:14:06 wiz Exp $

DISTNAME=		dopewars-1.5.0
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/ \
			${MASTER_SITE_SOURCEFORGE:=dopewars/} \
			http://berlin.sfai.edu/~tobi/dopewars/files/ \
			http://www.ideenpark.de/dopewars/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/
COMMENT=		Make a fortune dealing drugs on the streets of New York

DEPENDS+=		glib>=1.2.0:../../devel/glib

USE_CURSES=		YES
USE_LIBINTL=		YES
USE_GMAKE=		YES
REPLACE_NCURSES=	${WRKSRC}/configure

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--disable-gui-client
# datadir is the place the score file is saved
CONFIGURE_ARGS+=	--datadir=/var/games

.include "../../mk/bsd.pkg.mk"
