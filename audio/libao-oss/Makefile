# $NetBSD: Makefile,v 1.2 2005/10/08 12:30:38 jmmv Exp $

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-oss/}

COMMENT+=	(OSS plugin)

NOT_FOR_PLATFORM+=	Darwin-*-* Interix-*-* SunOS-*-*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/ENABLE_OSS=no/ENABLE_OSS=yes/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/oss
INSTALL_DIRS=		${WRKSRC}/src/plugins/oss

SUBST_CLASSES+=		oss
SUBST_MESSAGE.oss=	"Fixing paths to OSS devices."
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/plugins/oss/ao_oss.c
SUBST_SED.oss=		-e 's|/dev/dsp|${DEVOSSAUDIO}|g'
SUBST_SED.oss+=		-e 's|/dev/sound/dsp|${DEVOSSAUDIO}|g'

BUILDLINK_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
