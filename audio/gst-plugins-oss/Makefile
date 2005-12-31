# $NetBSD: Makefile,v 1.3 2005/12/31 12:32:31 wiz Exp $
#

GST_PLUGINS_NAME=	oss
GST_PLUGINS_DIR=	sys/oss

.include "../../multimedia/gst-plugins/Makefile.common"
PKGREVISION=		1

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	"Fixing path to OSS audio device."
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
