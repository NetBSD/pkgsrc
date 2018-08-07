# $NetBSD: Makefile,v 1.2 2018/08/07 16:46:08 nia Exp $

DISTNAME=	retroarch-assets-${RETROARCH_VERSION}
PKGNAME=	libretro-glsl-shaders-${RETROARCH_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	-http://buildbot.libretro.com/stable/${PKGVERSION_NOREV}/windows-msvc2010/x86_64/RetroArch.7z
EXTRACT_SUFX=	.7z

HOMEPAGE=	https://www.libretro.com/
MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro GLSL shaders
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/shaders/shaders_glsl

do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} {} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;

.include "../../emulators/retroarch/version.mk"
.include "../../mk/bsd.pkg.mk"
