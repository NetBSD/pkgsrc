# $NetBSD: Makefile,v 1.6 1998/04/22 14:22:44 agc Exp $
#

DISTNAME=		xfig.3.2
PKGNAME=		xfig-3.2
WRKSRC=			${WRKDIR}/xfig.3.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=		root@garbled.futureone.com

RUN_DEPENDS=		fig2dev:${PORTSDIR}/print/transfig
DEPENDS+=		xpm-3.4j:../../graphics/xpm
DEPENDS+=		jpeg-6a:../../graphics/jpeg
DEPENDS+=		Xaw3d-1.3:../../x11/Xaw3d

USE_IMAKE=		yes

post-install:
	${MKDIR} ${X11BASE}/share/examples/xfig
	${MKDIR} ${X11BASE}/share/doc/xfig
	${CP} ${WRKSRC}/Examples/* ${X11BASE}/share/examples/xfig
	${CP} ${WRKSRC}/Doc/xfig.ps.gz ${X11BASE}/share/doc/xfig

.include "../../mk/bsd.pkg.mk"
