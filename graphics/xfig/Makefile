# $NetBSD: Makefile,v 1.22 2000/06/23 00:22:34 itohy Exp $
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
	@${MKDIR} ${XFIGEXAMPLES}
	@${CP} ${WRKSRC}/Examples/*.fig ${XFIGEXAMPLES}
	@${CP} ${WRKSRC}/Examples/*.gif ${XFIGEXAMPLES}
	@${CP} ${WRKSRC}/Examples/*.jpg ${XFIGEXAMPLES}
	@${CP} ${WRKSRC}/Examples/*.xbm ${XFIGEXAMPLES}
	@${CP} ${WRKSRC}/Examples/*.xpm ${XFIGEXAMPLES}

.include "../../mk/bsd.pkg.mk"
