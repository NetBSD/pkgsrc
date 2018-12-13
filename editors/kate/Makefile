# $NetBSD: Makefile,v 1.43 2018/12/13 19:51:50 adam Exp $

DISTNAME=	kate-${_KDE_VERSION}
PKGREVISION=	14
CATEGORIES=	editors
COMMENT=	KDE advanced text editor

PY_PATCHPLIST=	YES

.include "../../meta-pkgs/kde4/Makefile.kde4"

CHECK_PORTABILITY_SKIP+= examples/syntax/highlight.sh

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/qjson/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libkactivities4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/py-kde4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
