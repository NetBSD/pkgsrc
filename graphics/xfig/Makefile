# $NetBSD: Makefile,v 1.15 1998/09/13 19:35:06 garbled Exp $
#

DISTNAME=		xfig.3.2.2
PKGNAME=		xfig-3.2.2
WRKSRC=			${WRKDIR}/xfig.3.2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb1.lbl.gov/BVSmith/xfig/

DEPENDS+=		transfig-3.2.1:../../print/transfig
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		Xaw3d-1.5:../../x11/Xaw3d

CONFLICTS=		xfig-3.2

USE_IMAKE=		yes

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
