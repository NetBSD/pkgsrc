# $NetBSD: Makefile,v 1.44 2021/12/08 16:06:24 adam Exp $
#

PKGNAME=		amanda-plot-${AMANDA_VERSION}
PKGREVISION=		4

COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-server

MANPAGES+=		amplot.8

.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

BUILD_DIRS=		amplot

.include "../../mk/bsd.pkg.mk"
