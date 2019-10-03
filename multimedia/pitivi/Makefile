# $NetBSD: Makefile,v 1.50 2019/10/03 14:59:48 nia Exp $

DISTNAME=	pitivi-0.999
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pitivi/0.999/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pitivi.org/
COMMENT=	Video editor
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config intltool msgfmt xgettext

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Setting the Python executable name.
SUBST_FILES.py+=	meson.build
SUBST_VARS.py+=		PYVERSSUFFIX

REPLACE_PYTHON+=	bin/pitivi.in

# Python 3 only
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-meson/build.mk"
.include "../../graphics/gst-plugins1-gdk_pixbuf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/gst-plugins1-editing-services/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../multimedia/gst-plugins1-gtk/buildlink3.mk"
.include "../../multimedia/gst-plugins1-transcoder/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
