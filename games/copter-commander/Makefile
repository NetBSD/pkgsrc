# $NetBSD: Makefile,v 1.5 2003/05/02 11:54:53 wiz Exp $
#

DISTNAME=	copter-commander-1.8
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=coco/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.speakeasy.org/~morse/copter-commander/
COMMENT=	Armor Alley/Rescue Raiders clone

USE_GMAKE=	yes
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
