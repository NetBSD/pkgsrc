# $NetBSD: Makefile,v 1.34 2003/01/14 06:37:07 rh Exp $
#

DISTNAME=		xfig.3.2.4.full
PKGNAME=		xfig-3.2.4
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

XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT* ${XFIGDOCDIR}

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/Xaw3d/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
