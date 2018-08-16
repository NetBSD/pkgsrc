# $NetBSD: Makefile,v 1.13 2018/08/16 18:54:37 adam Exp $

PKGREVISION= 9
.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-filetransfer-handler-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://community.kde.org/KTp
COMMENT=	KDE Telepathy file transfer handling
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt
BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

.include "../../chat/ktp-common-internals/buildlink3.mk"
.include "../../chat/ktp-contact-list/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
