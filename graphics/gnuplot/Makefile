# $NetBSD: Makefile,v 1.46 2009/08/26 20:22:51 sno Exp $

PKGREVISION=		3
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=		gnuplot-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
