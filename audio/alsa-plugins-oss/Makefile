# $NetBSD: Makefile,v 1.7 2012/09/11 23:59:23 asau Exp $
#

DISTNAME=	alsa-plugins-1.0.22
PKGNAME=	${DISTNAME:S/plugins/plugins-oss/}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.alsa-project.org/
COMMENT=	Advanced Linux Sound Architecture (ALSA) - OSS plugin

GNU_CONFIGURE=	yes
USE_TOOLS=	pkg-config gmake
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEIN=SOUND_MIXER_PHONE
CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEOUT=SOUND_MIXER_MONO
CFLAGS.SunOS+=	-DSOUND_MIXER_MONITOR=SOUND_MIXER_DEPTH
CFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
LIBS+=		${LIBOSSAUDIO}

BUILD_DIRS=	oss

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
