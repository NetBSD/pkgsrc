# $NetBSD: Makefile,v 1.7 2004/06/26 06:40:08 grant Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
