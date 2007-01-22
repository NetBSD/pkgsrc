# $NetBSD: Makefile,v 1.36 2007/01/22 22:14:26 joerg Exp $
#

PKGREVISION=		6
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=             gnuplot-nox11-[0-9]*


.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
