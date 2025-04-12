# $NetBSD: Makefile,v 1.1 2025/04/12 18:37:15 jmcneill Exp $

DISTNAME=	1.7
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=wb2osz/}
GITHUB_PROJECT=	direwolf
GITHUB_TAG=	refs/tags/1.7
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	https://github.com/wb2osz/direwolf/
COMMENT=	Software "soundcard" AX.25 packet modem/TNC and APRS encoder/decoder
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DPKGSRC=TRUE -DINSTALL_PREFIX=${PREFIX}
CMAKE_CONFIGURE_ARGS+=	-DPORTAUDIO_INCLUDE_DIRS=${BUILDLINK_DIR}/include/portaudio2
CMAKE_CONFIGURE_ARGS+=	-DPORTAUDIO_LIBRARIES=${BUILDLINK_DIR}/lib/portaudio2/libportaudio.so

.include "options.mk"

WRKSRC=		${WRKDIR}/direwolf-1.7
USE_LANGUAGES=	c c++

.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
