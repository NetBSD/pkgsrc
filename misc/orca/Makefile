# $NetBSD: Makefile,v 1.53 2020/03/26 14:30:01 nia Exp $

DISTNAME=	orca-3.34.1
PKGREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/orca/3.34/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Orca
COMMENT=	Screen reader
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-at-spi2-[0-9]*:../../devel/py-at-spi2
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1

GNU_CONFIGURE=	yes
PY_PATCHPLIST=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

# Python 3 only
PYTHON_VERSIONS_INCOMPATIBLE=	27

CHECK_PORTABILITY_SKIP+=	run_pylint.sh.in

.include "../../devel/glib2/schemas.mk"
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
