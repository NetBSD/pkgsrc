# $NetBSD: Makefile,v 1.1.1.1 2009/11/21 20:04:06 markd Exp $

DISTNAME=	polkit-qt-0.9.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_KDE:=apps/KDE4.x/admin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://api.kde.org/kdesupport-api/kdesupport-apidocs/polkit-qt/html
COMMENT=	Qt Wrapper around PolicyKit
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	polkit-qt-core.pc.cmake polkit-qt-gui.pc.cmake polkit-qt.pc.cmake

.include "../../security/policykit/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
