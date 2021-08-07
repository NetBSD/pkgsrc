# $NetBSD: Makefile,v 1.162 2021/08/07 07:58:24 nia Exp $

DISTNAME=	pulseaudio-15.0
CATEGORIES=	audio
MASTER_SITES=	https://freedesktop.org/software/pulseaudio/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/PulseAudio
COMMENT=	Sound server for POSIX and Win32 systems
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

NOT_FOR_PLATFORM=	DragonFly-*-*

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Set OSS device node
SUBST_FILES.oss+=	src/modules/oss/module-oss.c
SUBST_FILES.oss+=	src/modules/module-detect.c
SUBST_VARS.oss+=	DEVOSSAUDIO

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_MESSAGE.egdir=	Set EGDIR for config file installation for pkgsrc
SUBST_FILES.egdir+=	src/pulse/meson.build
SUBST_FILES.egdir+=	src/daemon/meson.build
SUBST_VARS.egdir+=	EGDIR

# Requires --desktop in msgfmt.
_TOOLS_USE_PKGSRC.msgfmt=	yes

LIBTOOL_REQD=	2.4
GCC_REQD+=	4.8

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run gmake gm4
USE_TOOLS+=		msgfmt perl:build pkg-config
MESON_ARGS+=		-Dtcpwrap=disabled
MESON_ARGS+=		--localstatedir=${VARBASE}
MESON_ARGS+=		--sysconfdir=${PKG_SYSCONFBASEDIR}
MESON_ARGS+=		-Dfftw=disabled
MESON_ARGS+=		-Ddoxygen=false
CONFIGURE_ENV+=		DATADIRNAME=${PKGLOCALEDIR}
PKGCONFIG_OVERRIDE+=	libpulse-mainloop-glib.pc.in
PKGCONFIG_OVERRIDE+=	libpulse-simple.pc.in
PKGCONFIG_OVERRIDE+=	libpulse.pc.in

TOOL_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

REPLACE_BASH+=	shell-completion/bash/pulseaudio git-version-gen
REPLACE_BASH+=	src/utils/pa-info

.include "../../mk/bsd.prefs.mk"

# Some tests are incompatible for NetBSD at least
.if ${OPSYS} == "NetBSD"
MESON_ARGS+=		-Dtests=false
.endif

# broken test for TLS
.if ((${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[45].*)) || \
     (${OPSYS} == "Darwin" && !empty(PKGSRC_COMPILER:Mclang)))
CONFIGURE_ENV+=		ac_cv_tls=none
.endif

# Wrong sys/capability.h assumptions, incompatible implementation:

CONFIGURE_ENV+=		EGDIR=${EGDIR}

MAKE_FLAGS+=		bashcompletiondir=${PREFIX}/share/bash-completion/completions

# Use native atomic ops on NetBSD >= 5.0, otherwise
# fallback to libatomic_ops
.if !(${OPSYS} == "NetBSD" && exists(/usr/include/sys/atomic.h))
.include "../../devel/libatomic_ops/buildlink3.mk"
.endif

# Version number in patch-configure.ac.must be changed too.
PLIST_SUBST+=		PULSELIBVER=15.0
PLIST_VARS+=		alsa bonjour coreaudio evdev oss sun

# Build module-mmkbd-evdev.so under Linux
.if ${OPSYS} == "Linux"
.  if exists(/usr/include/linux/input.h)
PLIST.evdev=		yes
.  endif
.  if exists(/usr/include/linux/soundcard.h)
PLIST.oss=		yes
.  endif
PLIST.alsa=		yes
.include "../../audio/alsa-lib/buildlink3.mk"
.elif ${OPSYS} == "SunOS"
USE_LANGUAGES+=		c99
PLIST.sun=		yes
.  if ${OS_VERSION} == "5.11"
PLIST.oss=		yes
.  endif
.elif ${OPSYS} == "Darwin"
PLIST.bonjour=		yes
PLIST.coreaudio=	yes
.else
PLIST.oss=		yes
.endif

.include "options.mk"

# LIBS is not passed to meson build system. Use LDFLAGS instead.
LDFLAGS.NetBSD+=	${LIBOSSAUDIO}
LDFLAGS.SunOS+=		-lsocket -lnsl

# Do not depend on RPATH $ORIGIN.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulse-${PKGVERSION_NOREV}/modules

INSTALLATION_DIRS=	share/examples/pulse

PULSE_USER?=		pulse
PULSE_GROUP?=		pulse
PULSE_GROUP_REALTIME?=	pulsert
PULSE_GROUP_ACCESS?=	pulseacc

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

PKG_SYSCONFSUBDIR=	pulse
EGDIR=			${PREFIX}/share/examples/pulseaudio
CONF_FILES=		${EGDIR}/client.conf ${PKG_SYSCONFDIR}/client.conf
CONF_FILES+=		${EGDIR}/daemon.conf ${PKG_SYSCONFDIR}/daemon.conf
CONF_FILES+=		${EGDIR}/default.pa ${PKG_SYSCONFDIR}/default.pa
CONF_FILES+=		${EGDIR}/system.pa ${PKG_SYSCONFDIR}/system.pa
CONF_FILES+=		${EGDIR}/dbus-1/system.d/pulseaudio-system.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/pulseaudio-system.conf

PKG_GROUPS=		${PULSE_GROUP}
PKG_GROUPS+=		${PULSE_GROUP_REALTIME}
PKG_GROUPS+=		${PULSE_GROUP_ACCESS}
PKG_USERS=		${PULSE_USER}:${PULSE_GROUP}

.include "../../devel/meson/build.mk"
.if ${OPSYS} != Linux && ${OPSYS} != "Darwin"
.include "../../sysutils/consolekit/buildlink3.mk"
.endif
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
