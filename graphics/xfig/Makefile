# $NetBSD: Makefile,v 1.41 2005/02/18 15:56:18 wiz Exp $

DISTNAME=	xfig.3.2.4.full
PKGNAME=	xfig-3.2.4
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.xfig.org/xfigdist/

PATCH_SITES=	ftp://ftp.visi.com/users/hawkeyd/X/
PATCHFILES=	xfig-3.2.4-Xaw3d-1.5E.udiff

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.xfig.org/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=	transfig>=3.2.4:../../print/transfig
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_DEPENDS.Xaw3d+=	Xaw3d>=1.5E

WRKSRC=			${WRKDIR}/xfig.3.2.4
USE_BUILDLINK3=		YES
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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
