# $NetBSD: Makefile,v 1.7 2002/03/13 17:37:00 fredb Exp $
#

DISTNAME=	gnocatan-0.6.1
PKGREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	gnome version of the Settlers of Catan board game

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	yes

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
