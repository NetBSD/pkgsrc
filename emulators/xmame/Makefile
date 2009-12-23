# $NetBSD: Makefile,v 1.155 2009/12/23 18:42:43 joerg Exp $
#

DISTNAME=		xmame-0.106
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old arcade machines
LICENSE=		mame-license

RESTRICTED=		selling is not allowed
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CONFLICTS=		sdlmame-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
MAKE_FILE=		makefile.unix
TARGET=			${PKGBASE}
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

ROMPATH=		${PREFIX}/share/${TARGET}
SPOOLDIR=		${VARBASE}/games/${TARGET}

MAKE_FLAGS+=		TARGET="${TARGET:S/x//}"
MAKE_FLAGS+=		X11INC= X11LIB=

# Network support is broken since xmame-0.85
#MAKE_FLAGS+=		XMAME_NET=1

# Determine which CPU-specific code to use.
.for MARCH in alpha m68k i386 ia64 mips
MAME_CPU.${MARCH}?=	${MARCH}
.endfor
MAME_CPU.x86_64?=	amd64
.if !defined(MAME_CPU.${MACHINE_ARCH})
.  include "../../mk/endian.mk"
_MAME_CPU.big-endian=		risc
_MAME_CPU.little-endian=	risc_lsb
_MAME_CPU.unknown-endian=	risc		# assume unknown == big
MAME_CPU.${MACHINE_ARCH}?=	${_MAME_CPU.${MACHINE_ENDIAN}-endian}
.endif

# Determine which operating system defaults to use.
MAME_ARCH.NetBSD?=	netbsd
MAME_ARCH.Linux?=	linux
MAME_ARCH.SunOS?=	solaris
MAME_ARCH.DragonFly?=	dragonfly
.if !defined(MAME_ARCH.${OPSYS})
MAME_ARCH.${OPSYS}?=	generic
.endif

MAKE_FLAGS+=		DISPLAY_METHOD=${MAME_DISP_METHOD:Q}
MAKE_FLAGS+=		MY_CPU="${MAME_CPU.${MACHINE_ARCH}}"
MAKE_FLAGS+=		ARCH="${MAME_ARCH.${OPSYS}}"

.if ${X11_TYPE} == "modular"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
MAKE_FLAGS+=		X11_DGA=1
MAKE_FLAGS+=		X11_XV=1
.else
.  if exists(${X11BASE}/include/X11/extensions/xf86dga.h)
MAKE_FLAGS+=		X11_DGA=1
.  endif
.  if exists(${X11BASE}/include/X11/extensions/Xv.h)
MAKE_FLAGS+=		X11_XV=1
.  endif
.endif

# If supported, add appropriate definitions to build joystick drivers.
.if exists(/usr/include/machine/joystick.h) ||				\
    exists(/usr/include/linux/joystick.h)
MAKE_FLAGS+=		JOY_STANDARD=1
.endif
.if ${OPSYS} == "NetBSD"
.  if exists(/usr/lib/libusb.a) || exists(/usr/lib/libusbhid.a)
MAKE_FLAGS+=		JOY_USB=1
.  endif
.endif

OWN_DIRS=		${SPOOLDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

post-configure:
	cd ${WRKSRC}/doc;						\
	${SED}	-e "s|@ROMPATH@|${ROMPATH}|g"				\
		-e "s|@SPOOLDIR@|${SPOOLDIR}|g"				\
		${TARGET}rc.dist > ${TARGET}rc
.if !empty(MAKE_FLAGS:M*USB*)
	${LN} -fs /usr/include/usb.h ${BUILDLINK_DIR}/include
	for FILE in /usr/lib/libusb*; do				\
		${LN} -fs $$FILE ${BUILDLINK_DIR}/lib;			\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET}.${MAME_DISP_METHOD}	\
		${DESTDIR}${PREFIX}/bin/${TARGET}
	${INSTALL_PROGRAM} ${WRKSRC}/romcmp ${DESTDIR}${PREFIX}/bin/romcmp
	${INSTALL_PROGRAM} ${WRKSRC}/chdman ${DESTDIR}${PREFIX}/bin/chdman
	${INSTALL_PROGRAM} ${WRKSRC}/xml2info ${DESTDIR}${PREFIX}/bin/xml2info
	${INSTALL_MAN} ${WRKSRC}/doc/${TARGET}.6			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/${TARGET}.6
	${INSTALL_DATA_DIR} ${DESTDIR}${ROMPATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${TARGET}rc			\
		${DESTDIR}${ROMPATH}/${TARGET}rc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/xmame/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html				\
		${DESTDIR}${PREFIX}/share/doc/html/xmame/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmame
	${INSTALL_DATA} ${WRKSRC}/doc/xmame-doc.txt			\
		${DESTDIR}${PREFIX}/share/doc/xmame

# Pragma once is not needed, and case warnings/errors on gcc
SUBST_CLASSES+=		pragma
SUBST_STAGE.pragma=	pre-configure
SUBST_FILES.pragma=	src/*.h src/*/*.h
SUBST_SED.pragma=	-e "s|\#pragma once||g"

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
