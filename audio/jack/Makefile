# $NetBSD: Makefile,v 1.36 2019/06/15 08:21:32 adam Exp $

DISTNAME=	jack-audio-connection-kit-0.125.0
PKGNAME=	${DISTNAME:S/audio-connection-kit-//}
CATEGORIES=	audio
MASTER_SITES=	http://jackaudio.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jackaudio.org/
COMMENT=	JACK audio connection kit
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

BUILD_DEFS+=		JACKD_DEFAULT_TMPDIR
BUILD_DEFS+=		JACKD_PROCFS_PATH

SET_LIBDIR=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-alsa
CONFIGURE_ARGS+=	--disable-firewire
CONFIGURE_ARGS+=	--disable-freebob
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--enable-timestamps
CONFIGURE_ARGS+=	--enable-resize
CONFIGURE_ENV+=		HAVE_DOXYGEN=no
CONFIGURE_ENV+=		ac_cv_header_readline_chardefs_h=yes
PKGCONFIG_OVERRIDE+=	jack.pc.in

PTHREAD_OPTS+=		require native

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE -lossaudio
CFLAGS.Linux+=		-D_GNU_SOURCE
CFLAGS.SunOS+=		-std=c99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

JACKD_DEFAULT_TMPDIR?=	/tmp

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
CFLAGS+=		-DJACK_HOST_HAS_BSD_POLL
.endif
###
### XXX Is there a way to properly use the emulation framework
###	for this?
###
.if exists(${PREFIX}/emul/linux/proc) && ${OPSYS} != "Linux"
JACKD_PROCFS_PATH?=	${PREFIX}/emul/linux/proc
.else
JACKD_PROCFS_PATH?=	/proc
.endif

.if exists(/dev/shm) && ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-default-tmpdir=/dev/shm
.else
CONFIGURE_ARGS+=	--with-default-tmpdir=${JACKD_DEFAULT_TMPDIR:Q}
.endif

PLIST_VARS=		coreaudio oss sunaudio
###
### XXX	This is untested.  Please file a PR and/or commit a fix should
###	any problems arise.
###
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-coreaudio
PLIST.coreaudio=	yes
.else
CONFIGURE_ARGS+=	--disable-coreaudio
.endif
###
### XXX The sun driver is buggy on NetBSD right now.  I hope to remedy
###	this shortly.
###
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-sun
PLIST.sunaudio=		yes
.else
CONFIGURE_ARGS+=	--disable-sun
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO}
CFLAGS+=		-DDEVOSSAUDIO=\"${DEVOSSAUDIO:U/dev/dsp}\"
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

SUBST_CLASSES+=		jacksrc
SUBST_FILES.jacksrc=	libjack/unlock.c
SUBST_MESSAGE.jacksrc=	Peforming substitutions in JACK sources.
SUBST_STAGE.jacksrc=	pre-build
SUBST_VARS.jacksrc=	PREFIX JACKD_PROCFS_PATH X11BASE

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_OPTIONS_VAR=	PKG_OPTIONS.jack
PKG_SUPPORTED_OPTIONS=	simd
# on 7.99.26/amd64:
# ./simd.c: In function 'x86_3dnow_add2f':
# ./simd.c:211:3: error: impossible constraint in 'asm'
#   asm volatile (
#PKG_SUGGESTED_OPTIONS=	simd

.  include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Msimd)
CONFIGURE_ARGS+=	--enable-dynsimd
.  else
CONFIGURE_ARGS+=	--disable-dynsimd
.  endif
.endif

BDB_ACCEPTED=	db4 db5
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}

post-extract:
	${MKDIR} ${WRKSRC}/config/os/netbsd
	${CP} ${FILESDIR}/atomicity.h ${WRKSRC}/config/os/netbsd

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
