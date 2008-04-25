# $NetBSD: Makefile,v 1.5 2008/04/25 11:16:25 bjs Exp $
#

DISTNAME=	jack-audio-connection-kit-${JACK_VERSION}
PKGNAME=	jack-${JACK_VERSION}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

JACK_VERSION=	0.110.0

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.jackaudio.org/
COMMENT=	JACK audio connection kit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	jack.pc.in

PTHREAD_OPTS+=		require native

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-freebob
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-firewire
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--enable-resize
CONFIGURE_ARGS+=	--enable-timestamps

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE

CONFIGURE_ENV+=         ac_cv_header_readline_chardefs_h=yes
 
JACKD_DEFAULT_TMPDIR?=	/tmp
JACKD_PROCFS_PATH?=	/proc

.include "../../mk/bsd.prefs.mk"

.if "${OPSYS:M*BSD}" != "" || ${OPSYS} == "Darwin"
CFLAGS+=		-DJACK_HOST_HAS_BSD_POLL
.endif

.if exists(/dev/shm) && ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-default-tmpdir=/dev/shm
.else
CONFIGURE_ARGS+=	--with-default-tmpdir=${JACKD_DEFAULT_TMPDIR:Q}
.endif

PLIST_VARS=		oss sunaudio

###
### XXX The sun driver is buggy on NetBSD right now.  I hope to remedy
###	this shortly.
###
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Solaris"
CONFIGURE_ARGS+=	--enable-sun
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=	--disable-sun
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+= 	--enable-oss
PLIST.oss=		yes
MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
CFLAGS+=		-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
.else
CONFIGURE_ARGS+= 	--disable-oss
.endif


SUBST_CLASSES+=	jacksrc
SUBST_FILES.jacksrc=	libjack/unlock.c
SUBST_MESSAGE.jacksrc=	Peforming substitutions in JACK sources.
SUBST_STAGE.jacksrc=	pre-build
SUBST_VARS.jacksrc=	PREFIX JACKD_PROCFS_PATH

post-extract:
	${RUN} \
	    ${MKDIR} ${WRKSRC}/config/os/netbsd && \
		${CP} ${FILESDIR}/atomicity.h \
		    ${WRKSRC}/config/os/netbsd

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
