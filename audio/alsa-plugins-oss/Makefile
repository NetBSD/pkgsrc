# $NetBSD: Makefile,v 1.12 2016/09/15 20:33:02 wiedi Exp $

DISTNAME=	alsa-plugins-1.1.1
PKGNAME=	${DISTNAME:S/plugins/plugins-oss/}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - OSS plugin
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEIN=SOUND_MIXER_PHONE
CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEOUT=SOUND_MIXER_MONO
CFLAGS.SunOS+=	-DSOUND_MIXER_MONITOR=SOUND_MIXER_DEPTH
CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t
CFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
LIBS+=		${LIBOSSAUDIO}

BUILD_DIRS=	oss

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
