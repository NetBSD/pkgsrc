# $NetBSD: Makefile,v 1.1 2016/01/17 15:20:38 jaapb Exp $

.include "../../meta-pkgs/kde-telepathy/Makefile.common"
DISTNAME=	ktp-contact-runner-${KTP_VERSION}
CATEGORIES=	chat kde
MASTER_SITES=	${MASTER_SITE_KDE:=kde-telepathy/${KTP_VERSION}/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://community.kde.org/KTp
COMMENT=	KDE Telepathy KRunner integration module
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

.include "../../chat/ktp-common-internals/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
