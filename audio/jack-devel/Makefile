# $NetBSD: Makefile,v 1.1.1.1 2008/03/16 09:26:46 bjs Exp $
#

DISTNAME=	jack-0.109.10
PKGNAME=	${DISTNAME:C/jack/&-devel/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.jackaudio.org/
COMMENT=	JACK audio connection kit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-freebob
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-firewire
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--disable-sse

CONFIGURE_ARGS+=	--enable-resize
CONFIGURE_ARGS+=	--enable-timestamps

CONFIGURE_ARGS+=	--with-default-tmpdir=/tmp/

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	--enable-sun
PLIST_SUBST+=		SUN=""
.else
CONFIGURE_ARGS+=	--disable-sun
PLIST_SUBST+=		SUN="@comment "
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+= 	--enable-oss
PLIST_SUBST+=		OSS=""
MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q}
.else
CONFIGURE_ARGS+= 	--disable-oss
PLIST_SUBST+=	 	OSS="@comment "
.endif


PKGCONFIG_OVERRIDE+=	jack.pc.in
PTHREAD_OPTS+=		require native

CFLAGS.NetBSD+=		-DJACKD_WATCHDOG_TIMEOUT=900

JACKD_PROCFS_PATH?=	/proc

SUBST_CLASSES+=	jacksrc
SUBST_FILES.jacksrc=	libjack/unlock.c
SUBST_MESSAGE.jacksrc=	Peforming substitutions in JACK sources.
SUBST_STAGE.jacksrc=	pre-build
SUBST_VARS.jacksrc=	PREFIX JACKD_PROCFS_PATH

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
