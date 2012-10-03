# $NetBSD: Makefile,v 1.12 2012/10/03 11:43:43 asau Exp $
#

DISTNAME=	scite229
PKGNAME=	scite-2.29
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editor
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/scite
USE_LANGUAGES=	c c++
BUILD_DIRS+=	gtk
USE_TOOLS+=	gmake pkg-config
MAKE_FILE=	makefile
INSTALLATION_DIRS= share/applications share/pixmaps

post-extract:
	${RM} -r ${WRKDIR}/scintilla
	${RM} ${WRKSRC}/gtk/deps.mak
	${TOUCH} ${WRKSRC}/gtk/deps.mak

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/scintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
