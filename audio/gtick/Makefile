# $NetBSD: Makefile,v 1.68 2022/07/02 16:53:05 ryoon Exp $
#

DISTNAME=	gtick-0.5.5
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://www.antcom.de/gtick/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.antcom.de/gtick/
COMMENT=	Metronome application using GTK2+
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

LIBS+=			${LIBOSSAUDIO}

SUBST_CLASSES+=		oss
SUBST_MESSAGE.oss=	Fixing paths to OSS devices.
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/globals.h
SUBST_SED.oss=		-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
