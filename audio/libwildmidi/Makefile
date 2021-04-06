# $NetBSD: Makefile,v 1.11 2021/04/06 07:53:56 wiz Exp $

DISTNAME=	wildmidi-0.4.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mindwerks/}
GITHUB_PROJECT=	wildmidi
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	https://www.mindwerks.net/projects/wildmidi/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/wildmidi-${DISTNAME}
USE_LANGUAGES=	c99
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-DWANT_OPENAL=ON
.else
CMAKE_ARGS+=	-DWANT_OPENAL=OFF
.endif

.if ${OPSYS} == "Linux"
CMAKE_ARGS+=	-DWANT_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
.  include "../../mk/oss.buildlink3.mk"
.  if ${OSS_TYPE} != "none"
CMAKE_ARGS+=	-DWANT_OSS=ON
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
