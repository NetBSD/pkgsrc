# $NetBSD: Makefile,v 1.3 2026/01/27 08:39:26 wiz Exp $

DISTNAME=	kmymoney-5.2.1
PKGREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_KDE:=kmymoney/${PKGVERSION_NOREV}/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://kmymoney.org/
COMMENT=	Personal Finance Manager for humans
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde/applications.mk"

CHECK_PORTABILITY_SKIP+=	tools/ci-run-docker-image.sh

USE_TOOLS+=		perl:run pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++

REPLACE_PERL+=		kmymoney/misc/financequote.pl

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=True
CMAKE_CONFIGURE_ARGS+=	-DDOXYGEN_EXECUTABLE=False

.include "../../lang/python/application.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../finance/alkimia/buildlink3.mk"
BUILDLINK_API_DEPENDS.libofx+=  libofx>=0.10.9
.include "../../finance/libofx/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
