# $NetBSD: Makefile,v 1.9 2002/09/10 16:06:32 wiz Exp $
#

DISTNAME=		oregano-0.20
PKGREVISION=		2
CATEGORIES=		cad gnome
MASTER_SITES=		http://www.dtek.chalmers.se/~d4hult/oregano/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.dtek.chalmers.se/~d4hult/oregano/
COMMENT=		application for schematic capture/simulation of electrical circuits

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libglade/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
