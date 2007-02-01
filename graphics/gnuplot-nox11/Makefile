# $NetBSD: Makefile,v 1.12 2007/02/01 12:15:39 drochner Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
PKGREVISION=		6
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
