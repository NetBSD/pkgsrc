# $NetBSD: Makefile,v 1.11 2022/08/11 05:08:00 gutteridge Exp $

DISTNAME=	adplay-1.8.1
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=adplug/}
GITHUB_PROJECT=	adplay-unix
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adplug/adplay-unix
COMMENT=	Console-based OPL2 audio player
LICENSE=	gnu-gpl-v2

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/oss.cc doc/adplay.1
SUBST_SED.oss=		-e s,/dev/dsp,${DEVOSSAUDIO},g
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.
.endif

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--disable-output-ao \
			--disable-output-esound

.if ${OSS_TYPE} != "none"
LDFLAGS+=		${LIBOSSAUDIO}
.else
CONFIGURE_ARGS+=	--disable-output-oss
.endif

.include "options.mk"
.include "../../audio/adplug/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
