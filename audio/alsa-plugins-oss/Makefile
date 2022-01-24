# $NetBSD: Makefile,v 1.17 2022/01/24 10:10:49 wiz Exp $

DISTNAME=	alsa-plugins-1.2.6
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

SUBST_CLASSES+=		audiodev
SUBST_STAGE.audiodev=	pre-configure
SUBST_FILES.audiodev=	oss/50-oss.conf
SUBST_VARS.audiodev=	DEVOSSAUDIO

CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEIN=SOUND_MIXER_PHONE
CFLAGS.SunOS+=	-DSOUND_MIXER_PHONEOUT=SOUND_MIXER_MONO
CFLAGS.SunOS+=	-DSOUND_MIXER_MONITOR=SOUND_MIXER_DEPTH
CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t
CFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

CFLAGS+=	-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
LIBS+=		${LIBOSSAUDIO}

BUILD_DIRS=	oss

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}
post-install:
	${INSTALL_DATA} "${FILESDIR}/asoundrc.example" \
		"${DESTDIR}${EGDIR}/asoundrc"

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
