# $NetBSD: Makefile,v 1.3 2018/09/06 09:33:38 nia Exp $

DISTNAME=	libretro-glsl-shaders-20180828
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	glsl-shaders
GITHUB_TAG=	a52c8b6798c7a10fd72971ef8e8b135e0f7a9ca0

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro GLSL shaders
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} {} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;

.include "../../mk/bsd.pkg.mk"
