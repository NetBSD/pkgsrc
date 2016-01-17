# $NetBSD: Makefile,v 1.1 2016/01/17 15:12:45 jaapb Exp $

.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-kded-integration-module-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://community.kde.org/KTp
COMMENT=	KDE Telepathy integration into KDE workspaces
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

.include "../../chat/ktp-common-internals/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
