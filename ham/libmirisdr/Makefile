# $NetBSD: Makefile,v 1.4 2015/01/26 07:05:04 dbj Exp $

PKGNAME=	libmirisdr-0.1
PKGREVISION=	1
DISTNAME=	libmirisdr-${VERSION}
VERSION=	59ba372
CATEGORIES=	ham
MASTER_SITES=	-http://cgit.osmocom.org/libmirisdr/snapshot/libmirisdr-${VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.osmocom.org/libmirisdr/
COMMENT=	Osmocom Mirics MSi2500 + MSi001 SDR library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake pkg-config
USE_CMAKE=	yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev

PLIST_SUBST+=			PKGREVISION=${PKGREVISION:U0}
SUBST_CLASSES+=			patchlevel
SUBST_STAGE.patchlevel=		pre-configure
SUBST_MESSAGE.patchlevel=	Fixing library version patchlevel
SUBST_FILES.patchlevel=		CMakeLists.txt
SUBST_SED.patchlevel=		-e 's,\(VERSION_INFO_PATCH_VERSION\) git,\1 ${PKGREVISION:U0},'

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
