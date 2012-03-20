# $NetBSD: Makefile,v 1.2 2012/03/20 00:57:47 markd Exp $

DISTNAME=	kate-${_KDE_VERSION}
CATEGORIES=	editors
COMMENT=	KDE advanced text editor

.include "../../meta-pkgs/kde4/Makefile.kde4"

CHECK_PORTABILITY_SKIP+= part/tests/hl/highlight.sh

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
