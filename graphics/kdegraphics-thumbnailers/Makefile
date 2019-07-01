# $NetBSD: Makefile,v 1.40 2019/07/01 04:08:21 ryoon Exp $

DISTNAME=	kdegraphics-thumbnailers-${_KDE_VERSION}
PKGREVISION=	13
CATEGORIES=	graphics
COMMENT=	Graphics file format thumbnailers for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
