# $NetBSD: Makefile,v 1.2 2016/07/09 06:38:08 wiz Exp $

DISTNAME=	ktexteditor-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced embeddable text editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge pkg-config perl

.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
