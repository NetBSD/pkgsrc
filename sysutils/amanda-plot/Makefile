# $NetBSD: Makefile,v 1.10 2002/10/25 19:09:15 wiz Exp $
#

DISTNAME=		amanda-2.4.2p2
PKGNAME=		amanda-plot-2.4.2p2
SVR4_PKGNAME=		amapl
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cs.umd.edu/pub/amanda/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.amanda.org/
COMMENT=		Visualizes the behavior of Amanda, a network backup system

DEPENDS+=		gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=		amanda-server-2.4.2p2:../../sysutils/amanda-server

USE_BUILDLINK2=		yes
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"
.include "../../sysutils/amanda-common/Makefile.common"

CONFIGURE_ARGS+=	--without-client
CONFIGURE_ARGS+=	--without-restore
CONFIGURE_ARGS+=	--without-amrecover
CONFIGURE_ENV+=		GNUPLOT="${LOCALBASE}/bin/gnuplot"

.include "../../sysutils/amanda-common/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
