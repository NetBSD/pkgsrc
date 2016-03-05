# $NetBSD: Makefile,v 1.107 2016/03/05 11:28:05 jperkin Exp $

DISTNAME=	pulseaudio-8.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://freedesktop.org/software/pulseaudio/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/PulseAudio
COMMENT=	Sound server for POSIX and Win32 systems
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

LIBTOOL_REQD=	2.4

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoheader autoconf automake gmake gm4 intltool msgfmt pkg-config
USE_LANGUAGES=	c c++

REPLACE_BASH=	shell-completion/bash/pulseaudio git-version-gen

.include "../../mk/bsd.prefs.mk"
# Some tests are incompatible for NetBSD at least
CONFIGURE_ARGS.NetBSD+=	--disable-default-build-tests
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[45].*)
# broken test for TLS
CONFIGURE_ENV+=		ac_cv_tls=none
.endif

CONFIGURE_ENV+=		DATADIRNAME=${PKGLOCALEDIR}
USE_PKGLOCALEDIR=	yes

# Wrong sys/capability.h assumptions, incompatible implementation:
CONFIGURE_ARGS.FreeBSD+=	--without-caps

CONFIGURE_ENV+=		EGDIR=${EGDIR}
MAKE_ENV+=		EGDIR=${EGDIR}

MAKE_FLAGS+=		bashcompletiondir=${PREFIX}/share/bash-completion/completions

CONFIGURE_ARGS+=	--enable-samplerate
CONFIGURE_ARGS+=	--disable-tcpwrap
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}

# Use native atomic ops on NetBSD >= 5.0, otherwise
# fallback to libatomic_ops
.if !(${OPSYS} == "NetBSD" && exists(/usr/include/sys/atomic.h))
.include "../../devel/libatomic_ops/buildlink3.mk"
.endif

# Build module-mmkbd-evdev.so under Linux
.if ${OPSYS} == "Linux" && exists(/usr/include/linux/input.h)
PLIST.evdev=		yes
.endif

.if ${OPSYS} == "Linux"
PLIST.alsa=		yes
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.include "options.mk"

PKGCONFIG_OVERRIDE+=	libpulse-mainloop-glib.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-simple.pc.in
PKGCONFIG_OVERRIDE+=	libpulse.pc.in

LIBS.NetBSD+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	share/examples/pulse

PULSE_USER?=		pulse
PULSE_GROUP?=		pulse
PULSE_GROUP_REALTIME?=	pulsert
PULSE_GROUP_ACCESS?=	pulseacc

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	pulse
EGDIR=		${PREFIX}/share/examples/pulseaudio
CONF_FILES=	${EGDIR}/client.conf ${PKG_SYSCONFDIR}/client.conf
CONF_FILES+=	${EGDIR}/daemon.conf ${PKG_SYSCONFDIR}/daemon.conf
CONF_FILES+=	${EGDIR}/default.pa ${PKG_SYSCONFDIR}/default.pa
CONF_FILES+=	${EGDIR}/system.pa ${PKG_SYSCONFDIR}/system.pa
CONF_FILES+=	${EGDIR}/pulseaudio-system.conf \
		${PKG_SYSCONFBASE}/dbus-1/system.d/pulseaudio-system.conf

PLIST_VARS+=		alsa bonjour coreaudio evdev oss sun

.if ${OPSYS} == "SunOS"
PLIST.sun=		yes
.  if ${OS_VERSION} == "5.11"
PLIST.oss=		yes
.  endif
.elif ${OPSYS} == "Darwin"
PLIST.bonjour=	yes
PLIST.coreaudio=	yes
.else
PLIST.oss=		yes
.endif

PKG_GROUPS=		${PULSE_GROUP}
PKG_GROUPS+=		${PULSE_GROUP_REALTIME}
PKG_GROUPS+=		${PULSE_GROUP_ACCESS}
PKG_USERS=		${PULSE_USER}:${PULSE_GROUP}

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.if ${OPSYS} != "Darwin"
.include "../../sysutils/consolekit/buildlink3.mk"
.endif
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/policykit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
