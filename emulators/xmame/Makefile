# $NetBSD: Makefile,v 1.77 2002/06/25 09:21:35 cjep Exp $
#

DISTNAME=		xmame-0.60.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/ \
			http://roms2.mame.dk/emu/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@netbsd.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old arcade machines

RESTRICTED=		"selling is not allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
USE_GMAKE=		YES
MAKEFILE=		makefile.unix
TARGET=			${PKGBASE}
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "arm32" || ${MACHINE_ARCH} == "arm")
.if (${CFLAGS:M-O2} == "-O2")
CFLAGS:=         ${CFLAGS:S/-O2/-O0/} 
.endif
.endif

ROMPATH=		${PREFIX}/share/${TARGET}
SPOOLDIR=		/var/games/${TARGET}

MAKE_FLAGS+=		TARGET="${TARGET:S/x//}"
MAKE_FLAGS+=		CC="${CC}"
MAKE_FLAGS+=		LIBS="${LDFLAGS} ${LIBS}"
MAKE_FLAGS+=		CFLAGS="${CFLAGS}"
MAKE_FLAGS+=		X11INC= X11LIB=

MAME_DISP_METHOD?=	x11

# Determine which CPU-specific code to use.
.for MARCH in i386 alpha m68k
MAME_CPU.${MARCH}?=	${MARCH}
.endfor
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
.if !defined(MAME_ARCH.${OPSYS})
MAME_ARCH.${OPSYS}?=	generic
.endif

MAKE_FLAGS+=		DISPLAY_METHOD="${MAME_DISP_METHOD}"
MAKE_FLAGS+=		MY_CPU="${MAME_CPU.${MACHINE_ARCH}}"
MAKE_FLAGS+=		ARCH="${MAME_ARCH.${OPSYS}}"

.if exists(${X11BASE}/include/X11/extensions/xf86dga.h)
MAKE_FLAGS+=		X11_DGA=1
.endif

# If supported, add appropriate definitions to build joystick drivers.
.if exists(/usr/include/machine/joystick.h) ||				\
    exists(/usr/include/linux/joystick.h)
MAKE_FLAGS+=		JOY_I386=1
.endif
.if ${OPSYS} == "NetBSD"
.  if exists(/usr/lib/libusb.a) || exists(/usr/lib/libusbhid.a)
MAKE_FLAGS+=		JOY_USB=1
.  endif
.endif

OWN_DIRS=		${SPOOLDIR}

post-configure:
	cd ${WRKSRC}/doc;						\
	${SED}	-e "s|@ROMPATH@|${ROMPATH}|g"				\
		-e "s|@SPOOLDIR@|${SPOOLDIR}|g"				\
		xmamerc.dist > ${TARGET}rc
.if ${MAKE_FLAGS:M*USB*} != ""
	${LN} -fs /usr/include/usb.h ${BUILDLINK_DIR}/include
	for FILE in /usr/lib/libusb*; do				\
	  ${LN} -fs $$FILE ${BUILDLINK_DIR}/lib;			\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET}.${MAME_DISP_METHOD}	\
		${PREFIX}/bin/${TARGET}
	${INSTALL_MAN} ${WRKSRC}/doc/xmame.6				\
		${PREFIX}/man/man6/${TARGET}.6
	${INSTALL_DATA_DIR} ${ROMPATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${TARGET}rc ${ROMPATH}/${TARGET}rc

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
