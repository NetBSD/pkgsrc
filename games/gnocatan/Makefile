# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:06 jlam Exp $
#

DISTNAME=	gnocatan-0.6.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	gnome version of the Settlers of Catan board game

DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
