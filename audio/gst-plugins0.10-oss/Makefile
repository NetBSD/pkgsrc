# $NetBSD: Makefile,v 1.15 2020/03/08 16:48:41 wiz Exp $
#

GST_PLUGINS0.10_NAME=	oss
GST_PLUGINS0.10_DIRS=	sys/oss
PKGREVISION=		3

.include "../../multimedia/gst-plugins0.10-good/Makefile.common"

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	Fixing path to OSS audio device.
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	sys/oss/*.c
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
