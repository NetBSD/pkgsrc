# $NetBSD: Makefile,v 1.4 2001/01/04 21:50:10 wiz Exp $

DISTNAME=		dopewars-1.4.8
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/ \
			${MASTER_SITE_SOURCEFORGE:=dopewars/} \
			http://berlin.sfai.edu/~tobi/dopewars/files/ \
			http://www.ideenpark.de/dopewars/files/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

USE_CURSES=		YES
USE_GMAKE=		YES
REPLACE_NCURSES=	${WRKSRC}/configure

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-networking
# datadir is the place the score file is saved
CONFIGURE_ARGS+=	--datadir=/var/games

.include "../../mk/bsd.pkg.mk"
