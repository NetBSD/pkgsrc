# $NetBSD: Makefile,v 1.19 1999/08/25 13:37:35 agc Exp $
#

DISTNAME=		xfig.3.2.2
PKGNAME=		xfig-3.2.2
WRKSRC=			${WRKDIR}/xfig.3.2.2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/xfig}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb1.lbl.gov/BVSmith/xfig/

DEPENDS+=		transfig-3.2.1:../../print/transfig
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		yes
USE_XAW=		yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=		3d

post-install:
	@${MKDIR} ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.fig ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.jpg ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.eps ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.xbm ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.gif ${X11BASE}/share/examples/xfig
	@${CP} ${WRKSRC}/Examples/*.xpm ${X11BASE}/share/examples/xfig
	@${RM} ${X11BASE}/share/doc/xfig/html/images/add-arrow-button.gif.bak \
	   ${X11BASE}/share/doc/xfig/html/images/open-compound-button.gif.bak \
	   ${X11BASE}/share/doc/xfig/html/images/screen-image.fig.bak \
	   ${X11BASE}/share/doc/xfig/html/images/update-control.gif.bak

.include "../../mk/bsd.pkg.mk"
