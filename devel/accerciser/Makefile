# $NetBSD: Makefile,v 1.1.1.1 2009/01/16 23:38:22 wiz Exp $
#

DISTNAME=	accerciser-1.4.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/accerciser/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Interactive Python accessibility explorer for the GNOME desktop

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
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
