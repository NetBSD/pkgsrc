# $NetBSD: Makefile,v 1.4 2013/08/06 10:05:39 jmcneill Exp $
#

DISTNAME=	raspberrypi-userland-20130803
CATEGORIES=	misc
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/skrll/rpi/

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://github.com/jaredmcneill/userland
COMMENT=	Various libraries for the Raspberry Pi
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*arm

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
