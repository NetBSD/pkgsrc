# $NetBSD: Makefile,v 1.43 2008/06/20 01:09:22 joerg Exp $

SVR4_PKGNAME=		gplot
CATEGORIES+=		x11

CONFLICTS+=		gnuplot-nox11-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
