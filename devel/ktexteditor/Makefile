# $NetBSD: Makefile,v 1.17 2018/01/17 20:00:22 markd Exp $

DISTNAME=	ktexteditor-${KF5VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced embeddable text editor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge pkg-config perl

.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
