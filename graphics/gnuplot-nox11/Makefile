# $NetBSD: Makefile,v 1.11 2006/04/17 13:46:32 wiz Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
PKGREVISION=		5
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
