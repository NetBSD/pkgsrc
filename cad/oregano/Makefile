# $NetBSD: Makefile,v 1.25 2004/04/26 05:20:57 snj Exp $
#

DISTNAME=		oregano-0.20
PKGREVISION=		11
CATEGORIES=		cad gnome
MASTER_SITES=		http://www.dtek.chalmers.se/~d4hult/oregano/download/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.dtek.chalmers.se/~d4hult/oregano/
COMMENT=		Application for schematic capture/simulation of electrical circuits

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libglade/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
