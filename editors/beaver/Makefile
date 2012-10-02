# $NetBSD: Makefile,v 1.27 2012/10/02 17:10:53 tron Exp $
#

DISTNAME=	beaver${BEAVER_VERSION:S/./_/g}
PKGNAME=	beaver-${BEAVER_VERSION}
PKGREVISION=	12
CATEGORIES=	editors
MASTER_SITES=	http://download.savannah.gnu.org/releases/beaver/0.3.0.1%20-%202008.06.26/
EXTRACT_SUFX=	.tgz

BEAVER_VERSION=	0.3.0.1

MAINTAINER=	vincent.derrien@ahoup.net
HOMEPAGE=	http://www.nongnu.org/beaver/
COMMENT=	Lightweight GTK+ text editor with syntax highlighting

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DIRS=	src
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		iconpath
SUBST_FILES.iconpath=	beaver.desktop src/interface.c
SUBST_MESSAGE.iconpath=	Substituting hard-coded pathnames.
SUBST_STAGE.iconpath=	pre-build
SUBST_SED.iconpath=	-e 's,Icon=,&${PREFIX}/share/pixmaps/beaver/,'
SUBST_VARS.iconpath=	PREFIX

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
