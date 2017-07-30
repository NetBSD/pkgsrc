# $NetBSD: Makefile,v 1.12 2017/07/30 22:32:19 wiz Exp $
#

DISTNAME=	userland-20170109
PKGREVISION=	1
PKGNAME=	raspberrypi-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaredmcneill/}
GITHUB_PROJECT=	userland
GITHUB_TAG=	734d76b0675685e9ec9148694f2cc00f58e5ebc0

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	https://github.com/jaredmcneill/userland
COMMENT=	Various libraries for the Raspberry Pi
LICENSE=	modified-bsd

EXTRACT_USING=                bsdtar

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_TOOLCHAIN_FILE=${WRKSRC}/makefiles/cmake/toolchains/arm-netbsdelf.cmake

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing hard-coded install paths.
SUBST_FILES.vc=		makefiles/cmake/vmcs.cmake
SUBST_SED.vc=		-e 's,/opt/vc,${PREFIX},g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
