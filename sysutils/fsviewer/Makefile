# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 10:38:11 wiz Exp $
#

DISTNAME=	FSViewer.app-0.2.3
PKGNAME=	FSViewer-0.2.3
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.csn.ul.ie/~clernong/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} icons.tar.gz

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.csn.ul.ie/~clernong/projects/fsviewer.html
COMMENT=	NextStep-like Filemanager for WindowMaker

DEPENDS+=	windowmaker>=0.64.0:../../wm/windowmaker

DIST_SUBDIR=	fsviewer
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# needed for the new location of WINGs include files -- can be removed
# when the application gets updated for windowmaker>=0.64.0
CFLAGS+=	-I${X11BASE}/include/WINGs

USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

post-install:
	cd ${PREFIX}/GNUstep/Apps/FSViewer.app && \
		${PAX} -zrf ${_DISTDIR}${DISTSUBDIR}/icons.tar.gz *.xpm *.tif

.include "../../mk/bsd.pkg.mk"
