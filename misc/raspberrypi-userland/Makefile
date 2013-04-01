# $NetBSD: Makefile,v 1.1.1.1 2013/04/01 21:02:02 jmcneill Exp $
#

DISTNAME=	raspberrypi-userland-20130128
CATEGORIES=	misc
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/rpi/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://github.com/jaredmcneill/userland
COMMENT=	Various libraries for the Raspberry Pi
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-arm

USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_TOOLCHAIN_FILE=${WRKSRC}/makefiles/cmake/toolchains/arm-netbsdelf.cmake
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing hard-coded install paths.
SUBST_FILES.vc=		makefiles/cmake/vmcs.cmake
SUBST_SED.vc=		-e 's,/opt/vc,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
