# $NetBSD: Makefile,v 1.1.1.1 1999/07/01 08:27:30 garbled Exp $

DISTNAME=		dopewars-1.4.3
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

DEPENDS+=		ncurses-1.9.9g:../../devel/ncurses

ALL_TARGET=		dopewars
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
