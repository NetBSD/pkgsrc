# $NetBSD: Makefile,v 1.30 2001/08/23 04:26:54 jlam Exp $
#

DISTNAME=		xfig.3.2.3d.full
PKGNAME=		xfig-3.2.3.4
WRKSRC=			${WRKDIR}/xfig.3.2.3d
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=applications/drawing_tools/xfig/} \
			ftp://www-epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb1.lbl.gov/BVSmith/xfig/
COMMENT=		CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=		transfig>=3.2.3.4:../../print/transfig

USE_IMAKE=		YES
XAW_TYPE?=		3d

NO_INSTALL_MANPAGES=	YES	# install.all does install.man
INSTALL_TARGET=		install install.all
CFLAGS+=		-I${BUILDLINK_DIR}/include/X11
MAKE_ENV+=		X11PREFIX=${X11PREFIX}

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} != "3d" && ${XAW_TYPE} != "xpm")
pre-configure:
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} 's/#define.XAW3D/XCOMM &/' Imakefile.bak > Imakefile
.endif

XFIGEXAMPLES=		${PREFIX}/share/examples/xfig
XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA_DIR} ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.fig ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.gif ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.jpg ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.xbm ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Examples/*.xpm ${XFIGEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT* ${XFIGDOCDIR}

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
