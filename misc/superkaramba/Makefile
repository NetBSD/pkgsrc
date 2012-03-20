# $NetBSD: Makefile,v 1.1 2012/03/20 06:35:29 markd Exp $

DISTNAME=	superkaramba-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	KDE desktop widgets

.include "../../meta-pkgs/kde4/Makefile.kde4"

PYTHON_VERSIONS_ACCEPTED= 27 26 25
#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
