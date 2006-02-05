# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:32 joerg Exp $
#

PKGNAME=                ${DISTNAME:C/-/-nox11-/}
PKGREVISION=	3
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
