# $NetBSD: Makefile,v 1.1 2024/02/29 14:15:41 bsiegert Exp $

DISTNAME=	pcaudiolib-1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=espeak-ng/}
GITHUB_PROJECT=	pcaudiolib
GITHUB_RELEASE=	1.2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espeak-ng/pcaudiolib/
COMMENT=	Provides a C API to different audio devices
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoconf autoreconf pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-netbsd
.else
CONFIGURE_ARGS+=	--without-netbsd
.endif

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-coreaudio
.else
CONFIGURE_ARGS+=	--without-coreaudio
.endif

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=         oss
SUBST_STAGE.oss=        pre-configure
SUBST_FILES.oss=        src/oss.c
SUBST_SED.oss=          -e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=      Fixing hardcoded audio device.
.endif

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fi

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
