# $NetBSD: Makefile,v 1.1.1.1 2002/03/08 16:45:35 wiz Exp $
#

DISTNAME=	copter-commander-1.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=coco/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.speakeasy.org/~morse/copter-commander/
COMMENT=	Armor Alley/Rescue Raiders clone

DEPENDS+=	gtkglarea>=1.2.2:../../x11/gtkglarea
DEPENDS+=	gnome-libs>=1.4.0:../../x11/gnome-libs

USE_GMAKE=	yes
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

.include "../../mk/bsd.pkg.mk"
