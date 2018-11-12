# $NetBSD: Makefile,v 1.11 2018/11/12 03:51:23 ryoon Exp $

DISTNAME=	polkit-qt-1-0.112.0
PKGNAME=	${DISTNAME:S/-qt-1-/-qt5-/}
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KDE:=apps/KDE4.x/admin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.kde.org/projects/kdesupport/polkit-qt-1
COMMENT=	Qt5 Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

#EXTRACT_USING=	gtar

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	polkit-qt5-1.pc.cmake polkit-qt5-agent-1.pc.cmake
PKGCONFIG_OVERRIDE+=	polkit-qt5-core-1.pc.cmake polkit-qt5-gui-1.pc.cmake

.include "../../security/polkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
