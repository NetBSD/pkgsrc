# $NetBSD: Makefile,v 1.7 2002/08/25 21:50:57 jlam Exp $
#

DISTNAME=	FSViewer.app-0.2.3
PKGNAME=	FSViewer-0.2.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.csn.ul.ie/~clernong/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} icons.tar.gz

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.csn.ul.ie/~clernong/projects/fsviewer.html
COMMENT=	NextStep-like Filemanager for WindowMaker

DIST_SUBDIR=	fsviewer
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# needed for the new location of WINGs include files -- can be removed
# when the application gets updated for windowmaker>=0.64.0
CFLAGS+=	-I${BUILDLINK_PREFIX.windowmaker}/include/WINGs

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes

post-install:
	cd ${PREFIX}/GNUstep/Apps/FSViewer.app && \
		${PAX} -zrf ${_DISTDIR}${DISTSUBDIR}/icons.tar.gz *.xpm *.tif

.include "../../wm/windowmaker/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
