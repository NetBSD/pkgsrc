# $NetBSD: Makefile,v 1.12 2019/12/15 23:15:01 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-oss/}
PKGREVISION=	1

COMMENT+=	(OSS plugin)

NOT_FOR_PLATFORM+=	Darwin-*-* Interix-*-* SunOS-5.[0-9]-* SunOS-5.10-*

CONFIGURE_ENV:=	${CONFIGURE_ENV:S/ac_cv_header_sys_soundcard_h=no//1}
CONFIGURE_ENV:=	${CONFIGURE_ENV:S/ac_cv_header_machine_soundcard_h=no//1}

BUILD_DIRS=		src/plugins/oss
INSTALL_DIRS=		src/plugins/oss

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
LDFLAGS+=		${LIBOSSAUDIO}
.else
PKG_SKIP_REASON=	"OSS not available"
.endif

SUBST_CLASSES+=		oss
SUBST_MESSAGE.oss=	Fixing paths to OSS devices.
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/plugins/oss/ao_oss.c
SUBST_SED.oss=		-e 's|/dev/dsp|${DEVOSSAUDIO}|g'
SUBST_SED.oss+=		-e 's|/dev/sound/dsp|${DEVOSSAUDIO}|g'

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
