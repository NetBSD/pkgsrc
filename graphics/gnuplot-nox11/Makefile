# $NetBSD: Makefile,v 1.14 2008/05/09 11:12:27 jmmv Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		6
SVR4_PKGNAME=		gplot

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
