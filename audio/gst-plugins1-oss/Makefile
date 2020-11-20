# $NetBSD: Makefile,v 1.4 2020/11/20 11:40:09 nia Exp $

GST_PLUGINS1_NAME=	oss
GST_PLUGINS1_DIRS=	sys/oss

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-good/Makefile.common"

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	Fixing path to OSS audio device.
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
PKG_SKIP_REASON+=	"No OSS implementation available."
.endif

.include "../../mk/bsd.pkg.mk"
