# $NetBSD: Makefile,v 1.23 2020/06/05 12:49:02 jperkin Exp $

PKGREVISION= 19
.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-auth-handler-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://community.kde.org/KTp
COMMENT=	KDE Telepathy KWallet integration module
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

DEPENDS+=	qca2-ossl-[0-9]*:../../security/qca2-ossl
BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

.include "../../chat/ktp-common-internals/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
