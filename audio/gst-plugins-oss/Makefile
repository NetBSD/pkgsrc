# $NetBSD: Makefile,v 1.1.1.1 2004/04/06 09:41:51 jmmv Exp $
#

GST_PLUGINS_NAME=	oss
GST_PLUGINS_DIR=	sys/oss

.include "../../multimedia/gst-plugins/Makefile.common"

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	"Fixing path to OSS audio device."
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
