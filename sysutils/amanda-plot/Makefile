# $NetBSD: Makefile,v 1.12 2003/06/02 01:16:57 jschauma Exp $
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-plot-2.4.2p2
SVR4_PKGNAME=		amapl
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.2p2:../../sysutils/amanda-server

USE_BUILDLINK2=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

.include "../../mk/bsd.pkg.mk"
