# $NetBSD: Makefile,v 1.20 2018/04/29 21:31:55 adam Exp $

DISTNAME=	ktux-15.08.3
PKGREVISION=	8
CATEGORIES=	misc
COMMENT=	Tux Screen Saver
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-workspace4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
