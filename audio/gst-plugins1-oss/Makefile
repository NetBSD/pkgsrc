# $NetBSD: Makefile,v 1.1 2012/11/29 08:42:38 ryoon Exp $
#

GST_PLUGINS1_NAME=	oss
GST_PLUGINS1_DIRS=	sys/oss

.include "../../multimedia/gst-plugins1-good/Makefile.common"

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	Fixing path to OSS audio device.
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
