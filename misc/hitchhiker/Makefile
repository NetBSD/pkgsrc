# $NetBSD: Makefile,v 1.4 2002/07/17 12:53:07 agc Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam
COMMENT=	Astronomical simulation and visualization program

GNU_CONFIGURE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

USE_BUILDLINK_ONLY=	yes

.include "../../graphics/glut/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../x11/gtkglarea/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
