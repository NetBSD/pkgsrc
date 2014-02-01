# $NetBSD: Makefile,v 1.20 2014/02/01 02:20:49 markd Exp $

DISTNAME=	kig-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	KDE interactive geometry

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PYTHON+=	pykig/pykig.py

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
