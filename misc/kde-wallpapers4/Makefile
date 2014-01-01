# $NetBSD: Makefile,v 1.19 2014/01/01 11:52:24 wiz Exp $

DISTNAME=	kde-wallpapers-${_KDE_VERSION}
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Wallpapers for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
