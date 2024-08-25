# $NetBSD: Makefile,v 1.15 2024/08/25 06:18:24 wiz Exp $

DISTNAME=	wildmidi-0.4.6
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mindwerks/}
GITHUB_PROJECT=	wildmidi
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://github.com/Mindwerks/wildmidi
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/wildmidi-${DISTNAME}
USE_LANGUAGES=	c99

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DWANT_OPENAL=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_OPENAL=OFF
.endif

.if ${OPSYS} == "Linux"
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
.  include "../../mk/oss.buildlink3.mk"
.  if ${OSS_TYPE} != "none"
CMAKE_CONFIGURE_ARGS+=	-DWANT_OSS=ON
.  endif
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
