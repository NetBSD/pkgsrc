# $NetBSD: Makefile,v 1.3 2011/04/22 13:43:27 obache Exp $
#

DISTNAME=	scite225
PKGNAME=	scite-2.25
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editor
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/scite
USE_LANGUAGES=	c c++
BUILD_DIRS+=	gtk
USE_TOOLS+=	gmake
MAKE_FILE=	makefile
INSTALLATION_DIRS= share/applications share/pixmaps

post-extract:
	${RM} -r ${WRKDIR}/scintilla
	${RM} ${WRKSRC}/gtk/deps.mak
	${TOUCH} ${WRKSRC}/gtk/deps.mak

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/scintilla/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
