# $NetBSD: Makefile,v 1.22 2012/09/11 23:59:37 asau Exp $

DISTNAME=	fluidsynth-1.1.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluidsynth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fluidsynth.org/
COMMENT=	Software synthesizer based on SoundFont2
LICENSE=	gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	fluidsynth.pc.in
PTHREAD_AUTO_VARS=	yes

CFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LDFLAGS+=		${LIBOSSAUDIO}

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t
CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t
CPPFLAGS.SunOS+=	-DSOUND_PCM_WRITE_CHANNELS=SNDCTL_DSP_CHANNELS
LIBS.SunOS+=		-lsocket

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
