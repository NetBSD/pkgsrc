# $NetBSD: Makefile,v 1.3 2000/01/15 18:46:27 jlam Exp $

DISTNAME=		dopewars-1.4.3
CATEGORIES=		games
MASTER_SITES=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://bellatrix.pcl.ox.ac.uk/~ben/dopewars/

DEPENDS+=		ncurses>=4.2:../../devel/ncurses

ALL_TARGET=		dopewars
LDFLAGS+=		-L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
