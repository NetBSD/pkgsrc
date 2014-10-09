# $NetBSD: Makefile,v 1.34 2014/10/09 13:44:56 wiz Exp $
#

PKGNAME=		amanda-plot-${AMANDA_VERSION}
PKGREVISION=		1

COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-${AMANDA_VERSION}{,nb[0-9]*}:../../sysutils/amanda-server

MANPAGES+=		amplot.8

.include "../../sysutils/amanda-common/Makefile.common"

FIND_PREFIX:=		GNUPLOT_PREFIX=gnuplot
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${GNUPLOT_PREFIX}/bin/gnuplot"

BUILD_DIRS=		amplot

.include "../../mk/bsd.pkg.mk"
