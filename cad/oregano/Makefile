# $NetBSD: Makefile,v 1.16 2003/05/30 16:19:51 jmmv Exp $
#

DISTNAME=		oregano-0.20
PKGREVISION=		6
CATEGORIES=		cad gnome
MASTER_SITES=		http://www.dtek.chalmers.se/~d4hult/oregano/download/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.dtek.chalmers.se/~d4hult/oregano/
COMMENT=		application for schematic capture/simulation of electrical circuits

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
