# $NetBSD: Makefile,v 1.10 2004/10/05 13:12:40 wiz Exp $

DISTNAME=		mpd-0.11.4
PKGNAME=		${DISTNAME:S/mpd/musicpd/}
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://mercury.chem.pitt.edu/~shank/

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Remote controllable audio player

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes

BUILD_DEFS+=		MUSICPD_WITH_AAC
BUILD_DEFS+=		MUSICPD_WITH_AUDIOFILE
BUILD_DEFS+=		MUSICPD_WITH_FLAC
BUILD_DEFS+=		MUSICPD_WITH_ICONV
BUILD_DEFS+=		MUSICPD_WITH_ID3
BUILD_DEFS+=		MUSICPD_WITH_OGG
#BUILD_DEFS+=		USE_INET6

.include "../../mk/bsd.prefs.mk"

MUSICPD_WITH_AAC?=	YES
MUSICPD_WITH_AUDIOFILE?=YES
MUSICPD_WITH_FLAC?=	YES
MUSICPD_WITH_ICONV?=	YES
MUSICPD_WITH_ID3?=	YES
MUSICPD_WITH_OGG?=	YES

EGDIR=			${PREFIX}/share/examples/mpd
RCD_SCRIPTS=		mpd

FILES_SUBST+=		DEVOSSAUDIO=${DEVOSSAUDIO}
LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	src/main.c
SUBST_SED.config=	-e s,/etc/mpd.conf,${PKG_SYSCONFDIR}/mpd.conf,

.if ${MUSICPD_WITH_AAC} == "YES"
.  include "../../audio/faad2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-faad=${BUILDLINK_PREFIX.faad2}
.else
CONFIGURE_ARGS+=	--disable-aac
.endif

.if ${MUSICPD_WITH_AUDIOFILE} == "YES"
.  include "../../audio/libaudiofile/buildlink3.mk"
CONFIGURE_ARGS+=	--with-audiofile=${BUILDLINK_PREFIX.audiofile}
CONFIGURE_ENV+=		ac_cv_lib_iconv_iconv_open=yes
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

.if ${MUSICPD_WITH_FLAC} == "YES"
.  include "../../audio/flac/buildlink3.mk"
CONFIGURE_ARGS+=	--with-flac=${BUILDLINK_PREFIX.flac}
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if ${MUSICPD_WITH_ICONV} == "YES"
.  include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${MUSICPD_WITH_ID3} == "YES"
.  include "../../audio/libid3tag/buildlink3.mk"
CONFIGURE_ARGS+=	--with-id3tag=${BUILDLINK_PREFIX.libid3tag}
.else
CONFIGURE_ARGS+=	--disable-id3
.endif

.if ${MUSICPD_WITH_OGG} == "YES"
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif

# when IPv6 support is enabled, mpd doesn't listen on an IPv4 address.
#.if defined(USE_INET6) && ${USE_INET6} == "YES"
#CONFIGURE_ARGS+=	--enable-ipv6
#.else
CONFIGURE_ARGS+=	--disable-ipv6
#.endif

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mpd.conf > ${WRKDIR}/mpd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mpd.conf ${EGDIR}

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
