# $NetBSD: Makefile,v 1.10 2004/01/24 13:30:55 grant Exp $
#

DISTNAME=	copter-commander-1.8
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=coco/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.speakeasy.org/~morse/copter-commander/
COMMENT=	Armor Alley/Rescue Raiders clone

USE_GNU_TOOLS+=	make
MAKE_ENV+=	X11PREFIX=${X11PREFIX}
MAKE_ENV+=	GTKGLAREADIR=${BUILDLINK_PREFIX.gtkglarea}
MAKE_ENV+=	OPENGLDIR=${BUILDLINK_PREFIX.MesaLib}
MAKE_ENV+=	TIFFDIR=${BUILDLINK_PREFIX.tiff}
MAKE_ENV+=	ESDDIR=${BUILDLINK_PREFIX.esound}

USE_BUILDLINK2=	yes

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
