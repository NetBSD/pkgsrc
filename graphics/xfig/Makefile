# $NetBSD: Makefile,v 1.36 2003/03/02 19:47:26 jschauma Exp $
#

DISTNAME=		xfig.3.2.4.full
PKGNAME=		xfig-3.2.4
PKGREVISION=		1
WRKSRC=			${WRKDIR}/xfig.3.2.4
CATEGORIES=		graphics
MASTER_SITES=		ftp://epb.lbl.gov/xfig/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://epb.lbl.gov/BVSmith/xfig/
COMMENT=		CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=		transfig>=3.2.4:../../print/transfig

USE_BUILDLINK2=		YES
USE_IMAKE=		YES
XAW_TYPE?=		3d

NO_INSTALL_MANPAGES=	YES	# install.all does install.man
INSTALL_TARGET=		install install.all
CFLAGS+=		-I${X11PREFIX}/include/X11

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} != "3d" && ${XAW_TYPE} != "xpm")
pre-configure:
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} 's/#define.XAW3D/XCOMM &/' Imakefile.bak > Imakefile
.endif

XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT* ${XFIGDOCDIR}

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
