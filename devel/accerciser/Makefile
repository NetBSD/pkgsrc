# $NetBSD: Makefile,v 1.3 2009/05/21 11:10:56 wiz Exp $
#

DISTNAME=	accerciser-1.6.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/accerciser/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Interactive Python accessibility explorer for the GNOME desktop
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		intltool pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24
PY_PATCHPLIST=		yes
REPLACE_PYTHON=		plugins/ipython_view.py
REPLACE_PYTHON+=	src/accerciser.in

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.py-at-spi+=	${PYPKGPREFIX}-at-spi>=1.23.3
.include "../../devel/py-at-spi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
