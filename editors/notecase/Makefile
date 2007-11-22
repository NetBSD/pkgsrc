# $NetBSD: Makefile,v 1.1.1.1 2007/11/22 20:50:09 drochner Exp $
#

DISTNAME=	notecase-1.7.2_src
PKGNAME=	notecase-1.7.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=notecase/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notecase.sourceforge.net/
COMMENT=	Hierarchical note manager

WRKSRC=		${WRKDIR}/notecase-1.7.2
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config gsed
TOOLS_PLATFORM.gsed= #empty, override nonsense in tools
USE_DIRS+=	xdg-1.1

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/notecase
	${INSTALL_DATA_DIR} ${PREFIX}/share/locale/fr_CA/LC_MESSAGES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
