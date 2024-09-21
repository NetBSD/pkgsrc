# $NetBSD: Makefile,v 1.1 2024/09/21 13:14:58 abs Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	android-tools-adb-${GITHUB_TAG:S:android-::C:_r:.:}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=aosp-mirror/}
GITHUB_PROJECT=	platform_system_core
GITHUB_TAG=	android-5.1.1_r29

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.android.com/tools/help/adb.html
COMMENT=	Android debug bridge command line tool
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/adb
USE_TOOLS+=	gmake

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0

INSTALLATION_DIRS+=	bin

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
