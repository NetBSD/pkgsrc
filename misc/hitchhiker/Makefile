# $NetBSD: Makefile,v 1.1.1.1 2001/01/04 18:43:41 wiz Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam

DEPENDS+=	gnome-libs>=1.2.8:../../x11/gnome-libs
DEPENDS+=	gtkglarea>=1.2.1:../../x11/gtkglarea

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
