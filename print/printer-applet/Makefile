# $NetBSD: Makefile,v 1.1.1.1 2012/03/20 06:21:42 markd Exp $

DISTNAME=	printer-applet-${_KDE_VERSION}
CATEGORIES=	print
COMMENT=	KDE printer applet

.include "../../meta-pkgs/kde4/Makefile.kde4"

PYTHON_VERSIONS_ACCEPTED= 27 26 25
#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

REPLACE_PYTHON+=	*.py

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../print/py-cups/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/py-kde4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
