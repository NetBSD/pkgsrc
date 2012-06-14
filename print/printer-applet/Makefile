# $NetBSD: Makefile,v 1.3 2012/06/14 07:44:49 sbd Exp $

DISTNAME=	printer-applet-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	print
COMMENT=	KDE printer applet

.include "../../meta-pkgs/kde4/Makefile.kde4"

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
