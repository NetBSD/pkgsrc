# $NetBSD: Makefile,v 1.3 2002/03/13 17:37:26 fredb Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam
COMMENT=	Astronomical simulation and visualization program

DEPENDS+=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs
DEPENDS+=	gtkglarea>=1.2.1:../../x11/gtkglarea

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
