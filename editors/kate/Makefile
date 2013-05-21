# $NetBSD: Makefile,v 1.14 2013/05/21 12:49:28 markd Exp $

DISTNAME=	kate-${_KDE_VERSION}
CATEGORIES=	editors
COMMENT=	KDE advanced text editor

PY_PATCHPLIST=	YES

.include "../../meta-pkgs/kde4/Makefile.kde4"

CHECK_PORTABILITY_SKIP+= part/tests/hl/highlight.sh

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kactivities/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/py-kde4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
