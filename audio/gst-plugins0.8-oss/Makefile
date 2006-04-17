# $NetBSD: Makefile,v 1.7 2006/04/17 14:52:11 wiz Exp $
#

GST_PLUGINS0.8_NAME=	oss
GST_PLUGINS0.8_DIR=	sys/oss

.include "../../multimedia/gst-plugins0.8/Makefile.common"
PKGREVISION=		5

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	"Fixing path to OSS audio device."
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
