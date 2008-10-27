# $NetBSD: Makefile,v 1.8 2008/10/27 00:33:42 wiz Exp $
#

DISTNAME=	orca-2.24.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/orca/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Orca
COMMENT=	Screen reader

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake msgfmt
USE_DIRS+=	xdg-1.1

PYTHON_VERSIONS_ACCEPTED= 25 24
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes

BUILDLINK_API_DEPENDS.gnome-speech+=	gnome-speech>=0.3.10
.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gnome-mag+=	gnome-mag>=0.12.5
.include "../../x11/gnome-mag/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
