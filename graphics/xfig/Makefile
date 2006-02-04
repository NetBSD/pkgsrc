# $NetBSD: Makefile,v 1.44 2006/02/04 13:17:51 markd Exp $

DISTNAME=	xfig.3.2.5-alpha5.full
PKGNAME=	xfig-3.2.5alpha5
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://epb.lbl.gov/xfig/alpha/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.xfig.org/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=	transfig>=3.2.4:../../print/transfig
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_DEPENDS.Xaw3d+=	Xaw3d>=1.5E

WRKSRC=			${WRKDIR}/xfig.3.2.5-alpha5
USE_IMAKE=		YES
XAW_TYPE?=		3d

NO_INSTALL_MANPAGES=	YES	# install.all does install.man
INSTALL_TARGET=		install install.all
CFLAGS+=		-I${X11PREFIX}/include/X11

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if defined(XAW_TYPE) && ${XAW_TYPE} == "3d"
	# define XAW3D and XAW3D1_5E
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} -e 's/.*\(#define.XAW3D\)/\1/' Imakefile.bak > Imakefile
.elif defined(XAW_TYPE) && ${XAW_TYPE} == "xpm"
	#  define XAW3D, undef XAW3D1_5E
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} -e 's/.*\(#define.XAW3D1_5E\)/XCOMM \1/' -e t \
	  	 -e 's/.*\(#define.XAW3D\)/\1/' Imakefile.bak > Imakefile
.else
	# undef XAW3D and XAW3D1_5E
	cd ${WRKSRC} &&	\
	  if [ ! -f Imakefile.bak ]; then ${MV} Imakefile Imakefile.bak; fi && \
	  ${SED} 's/.*\(#define.XAW3D\)/XCOMM \1/' Imakefile.bak > Imakefile
.endif

XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT* ${XFIGDOCDIR}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
