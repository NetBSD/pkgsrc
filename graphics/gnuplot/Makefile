# $NetBSD: Makefile,v 1.45 2009/05/20 00:58:17 wiz Exp $

PKGREVISION=		2
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=		gnuplot-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
