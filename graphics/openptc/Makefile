# $NetBSD: Makefile,v 1.7 2002/01/02 10:18:57 hubertf Exp $

DISTNAME=		OpenPTC-x11-1.0.0-2
PKGNAME=		OpenPTC-X11-1.0.02
CATEGORIES=		graphics
MASTER_SITES=		# only on NetBSD mirrors anymore

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.gaffer.org/ptc/
COMMENT=		Prometheus Truecolour for X11

WRKSRC=			${WRKDIR}/OpenPTC-x11-1.0.0

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes
CONFIGURE_ENV+=		CXXFLAGS="-I${BUILDLINK_DIR}/include"

.include "../hermes/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
