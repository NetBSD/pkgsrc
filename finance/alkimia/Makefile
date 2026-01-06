# $NetBSD: Makefile,v 1.1 2026/01/06 17:12:23 ryoon Exp $

DISTNAME=	alkimia-8.2.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_KDE:=alkimia/${PKGVERSION_NOREV}/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://community.kde.org/Alkimia
COMMENT=	FInancial infrastructure for common storage and business logic
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd AND gnu-gpl-v2 AND mit

CHECK_PORTABILITY_SKIP+=	tools/ci-run-docker-image.sh

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=True
CMAKE_CONFIGURE_ARGS+=	-DDOXYGEN_EXECUTABLE=False
CMAKE_CONFIGURE_ARGS+=	-DBUILD_APPLETS=False

PKGCONFIG_OVERRIDE+=	src/libalkimia.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
