# $NetBSD: Makefile,v 1.1 2016/01/17 15:22:44 jaapb Exp $

.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-send-file-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://community.kde.org/KTp
COMMENT=	KDE Telepathy file transfer application
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

DEPENDS+=	ktp-filetransfer-handler-${KTP_VERSION}{,nb[0-9]*}:../../chat/ktp-filetransfer-handler

.include "../../chat/ktp-common-internals/buildlink3.mk"
.include "../../chat/ktp-contact-list/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
