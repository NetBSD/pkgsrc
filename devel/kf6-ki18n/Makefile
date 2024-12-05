# $NetBSD: Makefile,v 1.7 2024/12/05 09:43:21 markd Exp $

DISTNAME=	ki18n-${KF6VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Advanced internationalization framework
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_TOOLS+=	msgfmt

CMAKE_CONFIGURE_ARGS+=	-DLibIntl_INCLUDE_DIRS=${BUILDLINK_PREFIX.gettext}/include

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
