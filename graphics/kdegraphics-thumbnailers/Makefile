# $NetBSD: Makefile,v 1.4 2012/09/07 19:16:48 adam Exp $

DISTNAME=	kdegraphics-thumbnailers-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	graphics file format thumbnailers for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libkdcraw/buildlink3.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
