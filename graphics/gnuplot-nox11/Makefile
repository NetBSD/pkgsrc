# $NetBSD: Makefile,v 1.20 2010/01/18 09:59:01 wiz Exp $
#

PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		1

CONFLICTS+=		gnuplot-[0-9]*

CONFIGURE_ARGS+=	--without-x

INSTALL_ENV+=		INSTALL_XRESOURCE_DATA=no

.include "../../graphics/gnuplot/Makefile.common"

.include "../../graphics/plotutils-nox11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
