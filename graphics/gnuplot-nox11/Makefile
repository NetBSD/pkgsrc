# $NetBSD: Makefile,v 1.8 2004/10/03 00:14:51 tv Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
PKGREVISION=	1
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
