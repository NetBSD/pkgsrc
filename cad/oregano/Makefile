# $NetBSD: Makefile,v 1.6 2001/09/27 23:17:46 jlam Exp $
#

DISTNAME=		oregano-0.20
CATEGORIES=		cad gnome
MASTER_SITES=		http://www.dtek.chalmers.se/~d4hult/oregano/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.dtek.chalmers.se/~d4hult/oregano/
COMMENT=		application for schematic capture/simulation of electrical circuits

DEPENDS+=		gnome-core-[0-9]*:../../x11/gnome-core
DEPENDS+=		gnome-print-[0-9]*:../../print/gnome-print
DEPENDS+=		libglade-[0-9]*:../../devel/libglade

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
