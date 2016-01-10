# $NetBSD: Makefile,v 1.29 2016/01/10 19:30:19 markd Exp $

DISTNAME=	kmousetool-15.12.0
CATEGORIES=	misc
COMMENT=	KDE mouse manipulation tool
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
