# $NetBSD: Makefile,v 1.9 2004/12/28 23:18:17 reed Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
PKGREVISION=	2
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
