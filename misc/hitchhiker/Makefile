# $NetBSD: Makefile,v 1.14 2004/03/08 19:40:40 jmmv Exp $
#

DISTNAME=	hh2000-0.6
PKGNAME=	hitchhiker-0.6
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hitchhiker/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hirame.hiram.edu/~worleyam
COMMENT=	Astronomical simulation and visualization program

DEPENDS+=		gnome1-dirs>=1.5:../../misc/gnome1-dirs

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtkglarea/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
