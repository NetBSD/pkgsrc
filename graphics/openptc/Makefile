# $NetBSD: Makefile,v 1.4 2000/08/14 19:23:43 wiz Exp $

DISTNAME=		OpenPTC-x11-1.0.0-2
PKGNAME=		OpenPTC-X11-1.0.02
CATEGORIES=		graphics
MASTER_SITES=		http://www.cs.ucl.ac.uk/students/c.nentwich/ptc/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.cs.ucl.ac.uk/students/c.nentwich/ptc/

DEPENDS+=		Hermes>=1.2.5:../../graphics/hermes

WRKSRC=			${WRKDIR}/OpenPTC-x11-1.0.0

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11BASE=		yes
CONFIGURE_ENV+=		CXXFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
