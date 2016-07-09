# $NetBSD: Makefile,v 1.35 2016/07/09 13:03:57 wiz Exp $

DISTNAME=	superkaramba-15.08.3
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	KDE desktop widgets
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

PYTHON_VERSIONS_INCOMPATIBLE=  34 35 # not yet ported as of 4.11.3

.include "../../meta-pkgs/kde4/Makefile.kde4"

#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
