# $NetBSD: Makefile,v 1.19 2009/09/14 18:52:03 asau Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
