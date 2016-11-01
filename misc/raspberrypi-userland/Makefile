# $NetBSD: Makefile,v 1.9 2016/11/01 16:45:27 skrll Exp $
#

DISTNAME=	userland-20161101
PKGNAME=	raspberrypi-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaredmcneill/}
GITHUB_PROJECT=	userland
GITHUB_TAG=	f23cb469c938c6035ebd9a285257743f9a2f9de1

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://github.com/jaredmcneill/userland
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
