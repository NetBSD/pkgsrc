# $NetBSD: Makefile,v 1.3 2001/10/05 14:16:04 wiz Exp $
#

DISTNAME=	FSViewer.app-0.2.3
PKGNAME=	FSViewer-0.2.3
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
CFLAGS+=	-I${BUILDLINK_DIR}/include/WINGs

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

post-install:
	cd ${PREFIX}/GNUstep/Apps/FSViewer.app && \
		${PAX} -zrf ${_DISTDIR}${DISTSUBDIR}/icons.tar.gz *.xpm *.tif

.include "../../wm/windowmaker/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
