# $NetBSD: Makefile,v 1.30 2004/10/03 00:14:51 tv Exp $
#

PKGREVISION=		1
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=             gnuplot-nox11-[0-9]*

USE_X11=		YES

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
