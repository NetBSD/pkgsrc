# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:27 agc Exp $
#

DISTNAME=		xfig.3.2
PKGNAME=		xfig-3.2
WRKSRC=			${WRKDIR}/xfig.3.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=		root@garbled.futureone.com

RUN_DEPENDS=		fig2dev:${PORTSDIR}/print/transfig
LIB_DEPENDS=		jpeg.7.:${PORTSDIR}/graphics/jpeg \
			Xpm.4.:${PORTSDIR}/graphics/xpm \
			Xaw3d.6.:${PORTSDIR}/x11/Xaw3d

USE_IMAKE=		yes

post-install:
	${MKDIR} ${X11BASE}/share/examples/xfig
	${MKDIR} ${X11BASE}/share/doc/xfig
	${CP} ${WRKSRC}/Examples/* ${X11BASE}/share/examples/xfig
	${CP} ${WRKSRC}/Doc/xfig.ps.gz ${X11BASE}/share/doc/xfig

.include "../../mk/bsd.pkg.mk"
