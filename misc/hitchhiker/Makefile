# $NetBSD: Makefile,v 1.2 2001/02/17 18:09:06 wiz Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam
COMMENT=	Astronomical simulation and visualization program

DEPENDS+=	gnome-libs>=1.2.8:../../x11/gnome-libs
DEPENDS+=	gtkglarea>=1.2.1:../../x11/gtkglarea

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
