# $NetBSD: Makefile,v 1.8 2002/07/16 14:55:03 agc Exp $

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

BUILDLINK_DEPENDS.Hermes=	Hermes>=1.3.2nb1

.include "../hermes/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
