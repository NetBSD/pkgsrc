# $NetBSD: Makefile,v 1.23 2000/07/27 14:01:00 jlam Exp $
#

DISTNAME=		xfig.3.2.3a
PKGNAME=		xfig-3.2.3a
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/xfig/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb1.lbl.gov/BVSmith/xfig/

DEPENDS+=		transfig-3.2.3:../../print/transfig
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		yes
USE_XAW=		yes

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=		3d

.if ${XAW_TYPE} != "3d"
pre-configure:
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} 's/#define.XAW3D/XCOMM &/' Imakefile.bak > Imakefile
.endif

XFIGEXAMPLES=		${PREFIX}/share/examples/xfig

post-install:
	${INSTALL_DATA_DIR} ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.fig ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.gif ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.jpg ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.xbm ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.xpm ${XFIGEXAMPLES}

.include "../../mk/bsd.pkg.mk"
