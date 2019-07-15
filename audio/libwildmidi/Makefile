# $NetBSD: Makefile,v 1.7 2019/07/15 14:39:54 nia Exp $

DISTNAME=	wildmidi-0.4.3
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mindwerks/}
GITHUB_PROJECT=	wildmidi
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mindwerks.net/projects/wildmidi/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/wildmidi-${DISTNAME}
USE_LANGUAGES=	c99
USE_TOOLS+=	gmake
USE_CMAKE=	yes

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	src/CMakeLists.txt
SUBST_STAGE.man=	post-extract
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DWANT_OPENAL=OFF
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
