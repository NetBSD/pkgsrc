# $NetBSD: Makefile,v 1.3 2000/08/16 00:07:32 wiz Exp $
#

DISTNAME=		oregano-0.11
CATEGORIES=		cad gnome
MASTER_SITES=		http://www.dtek.chalmers.se/~d4hult/oregano/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.dtek.chalmers.se/~d4hult/oregano/

DEPENDS+=		gnome-core-*:../../x11/gnome-core
DEPENDS+=		gnome-print-*:../../print/gnome-print
DEPENDS+=		libglade-*:../../devel/libglade

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
