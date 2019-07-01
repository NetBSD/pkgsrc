# $NetBSD: Makefile,v 1.40 2019/07/01 04:08:33 ryoon Exp $

DISTNAME=	kde-wallpapers-15.08.3
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	11
CATEGORIES=	misc
COMMENT=	Wallpapers for the KDE integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
