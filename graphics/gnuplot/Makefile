# $NetBSD: Makefile,v 1.44 2008/11/10 17:21:36 wiz Exp $

PKGREVISION=		1
SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=		gnuplot-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
