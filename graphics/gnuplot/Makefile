# $NetBSD: Makefile,v 1.31 2004/12/28 23:18:16 reed Exp $
#

PKGREVISION=		2
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=             gnuplot-nox11-[0-9]*

USE_X11=		YES

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
