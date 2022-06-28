# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:03 wiz Exp $

PKGREVISION= 31
.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-common-internals-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://community.kde.org/KTp
COMMENT=	KDE Telepathy common internal library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt
TOOLS_BROKEN+=	perl

DEPENDS+=	telepathy-mission-control5>=5.7.9:../../chat/telepathy-mission-control5
BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

.include "../../chat/libotr/buildlink3.mk"
.include "../../chat/telepathy-qt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
