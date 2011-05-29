# $NetBSD: Makefile,v 1.20 2011/05/29 00:38:59 obache Exp $
#

DISTNAME=	sonata-1.6.2
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/sonata/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sonata.berlios.de/
COMMENT=	Elegant GTK2 client for the Music Player Daemon

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25
PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
USE_TOOLS+=	pkg-config msgfmt

# gtk threading bugfix
BUILDLINK_ABI_DEPENDS.pygtk2+= ${PYPKGPREFIX}-gtk2>=2.12.1nb1

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../net/py-soappy/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../audio/py-mpd/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
