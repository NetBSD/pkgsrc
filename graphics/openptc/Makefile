# $NetBSD: Makefile,v 1.5 2001/02/16 15:22:28 wiz Exp $

DISTNAME=		OpenPTC-x11-1.0.0-2
PKGNAME=		OpenPTC-X11-1.0.02
CATEGORIES=		graphics
MASTER_SITES=		http://www.cs.ucl.ac.uk/students/c.nentwich/ptc/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.cs.ucl.ac.uk/students/c.nentwich/ptc/
COMMENT=		Prometheus Truecolour for X11

DEPENDS+=		Hermes>=1.2.5:../../graphics/hermes

WRKSRC=			${WRKDIR}/OpenPTC-x11-1.0.0

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes
CONFIGURE_ENV+=		CXXFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
