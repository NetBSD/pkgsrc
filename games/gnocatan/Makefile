# $NetBSD: Makefile,v 1.10 2003/06/02 01:19:40 jschauma Exp $
#

DISTNAME=	gnocatan-0.6.1
PKGREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	gnome version of the Settlers of Catan board game

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
