# $NetBSD: Makefile,v 1.18 2004/12/28 23:18:17 reed Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam
COMMENT=	Astronomical simulation and visualization program

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
