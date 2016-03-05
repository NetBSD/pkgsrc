# $NetBSD: Makefile,v 1.2 2016/03/05 11:28:08 jperkin Exp $

PKGREVISION= 1
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
