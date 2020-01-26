# $NetBSD: Makefile,v 1.8 2020/01/26 17:31:24 rillig Exp $

PKGNAME=	libmirisdr-0.1
PKGREVISION=	2
DISTNAME=	libmirisdr-${VERSION}
VERSION=	59ba372
CATEGORIES=	ham
MASTER_SITES=	-http://cgit.osmocom.org/libmirisdr/snapshot/libmirisdr-${VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.osmocom.org/libmirisdr/
COMMENT=	Osmocom Mirics MSi2500 + MSi001 SDR library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake pkg-config
USE_CMAKE=	yes

# Suppress warning for developer
CMAKE_ARGS+=	-Wno-dev

# Fix the shared library patchlevel
SHLIBPATCHLEVEL=		0
PLIST_SUBST+=			SHLIBPATCHLEVEL=${SHLIBPATCHLEVEL:U0}
SUBST_CLASSES+=			patchlevel
SUBST_STAGE.patchlevel=		pre-configure
SUBST_MESSAGE.patchlevel=	Fixing library version patchlevel
SUBST_FILES.patchlevel=		CMakeLists.txt
SUBST_SED.patchlevel=		-e 's,\(VERSION_INFO_PATCH_VERSION\) git,\1 ${SHLIBPATCHLEVEL:U0},'

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
