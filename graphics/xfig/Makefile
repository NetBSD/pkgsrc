# $NetBSD: Makefile,v 1.26 2001/08/07 11:58:41 tron Exp $
#

DISTNAME=		xfig.3.2.3a
PKGNAME=		xfig-3.2.3a
WRKSRC=			${WRKDIR}/${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/xfig/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb1.lbl.gov/BVSmith/xfig/
COMMENT=		CAD-like drawing tool.  Good for simple colorful scale drawings & ISO's

DEPENDS+=		transfig>=3.2.3:../../print/transfig
DEPENDS+=		jpeg-6b:../../graphics/jpeg

USE_IMAKE=		YES
USE_XAW=		YES
USE_XPM=		YES

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
