# $NetBSD: Makefile,v 1.7 2001/06/20 08:07:38 jlam Exp $

DISTNAME=		dopewars-1.5.0
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/ \
			${MASTER_SITE_SOURCEFORGE:=dopewars/} \
			http://berlin.sfai.edu/~tobi/dopewars/files/ \
			http://www.ideenpark.de/dopewars/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/
COMMENT=		Make a fortune dealing drugs on the streets of New York

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES

#USE_LIBINTL=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-networking
CONFIGURE_ARGS+=	--disable-gui-client
# datadir is the place the score file is saved
CONFIGURE_ARGS+=	--datadir=/var/games

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
