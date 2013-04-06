# $NetBSD: Makefile,v 1.10 2013/04/06 15:46:34 rodent Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-oss/}

COMMENT+=	(OSS plugin)

NOT_FOR_PLATFORM+=	Darwin-*-* Interix-*-* SunOS-5.[0-9]-* SunOS-5.10-*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/ENABLE_OSS=no/ENABLE_OSS=yes/g}
BUILD_DIRS=		src/plugins/oss
INSTALL_DIRS=		src/plugins/oss

SUBST_CLASSES+=		oss
SUBST_MESSAGE.oss=	Fixing paths to OSS devices.
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/plugins/oss/ao_oss.c
SUBST_SED.oss=		-e 's|/dev/dsp|${DEVOSSAUDIO}|g'
SUBST_SED.oss+=		-e 's|/dev/sound/dsp|${DEVOSSAUDIO}|g'

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
