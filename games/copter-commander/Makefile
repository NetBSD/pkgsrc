# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=	copter-commander-1.8
PKGREVISION=	5
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

USE_BUILDLINK3=	yes

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
