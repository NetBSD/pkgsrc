# $NetBSD: Makefile,v 1.27 2018/11/14 22:21:05 kleink Exp $

DISTNAME=	quodlibet-2.6.3
PKGREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	https://bitbucket.org/lazka/quodlibet-files/raw/default/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/quodlibet
COMMENT=	Finally a good alternative to iTunes
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins0.10-mad>=0.10.0:../../audio/gst-plugins0.10-mad
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.8:../../audio/py-mutagen
DEPENDS+=	gst-plugins0.10-vorbis>=0.10.0:../../audio/gst-plugins0.10-vorbis
DEPENDS+=	gst-plugins0.10-ogg>=0.10.0:../../multimedia/gst-plugins0.10-ogg

USE_TOOLS+=		msgfmt intltool
USE_PKGLOCALEDIR=	yes
#BUILD_TARGET=		_trayicon.so _mmkeys.so

PYDISTUTILSPKG= yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gstreamer0.10
REPLACE_PYTHON=	exfalso.py quodlibet.py operon.py

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
