# $NetBSD: Makefile,v 1.59 2001/12/17 07:10:15 tron Exp $
#

DISTNAME=		xmame-0.56.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://roms.mame.dk/emu/ \
			http://x.mame.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@netbsd.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old arcade and console machines

RESTRICTED=		"selling is not allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_X11BASE=		YES
USE_GMAKE=		YES
MAKEFILE=		makefile.unix
TARGET=			${PKGBASE}

.include "../../mk/bsd.prefs.mk"

ROMPATH=		${PREFIX}/share/${TARGET}
SPOOLDIR=		/var/games/${TARGET}

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
# Determine the endianness of the CPU by checking header files.
.  if !defined(MACHINE_ENDIAN)
_ENDIAN_H_FILES=	/usr/include/sys/endian.h
_ENDIAN_H_FILES+=	/usr/include/machine/endian.h
_ENDIAN_H_FILES+=	/usr/include/endian.h
_ENDIAN_H_FILES+=	/usr/include/sys/byteorder.h
_ENDIAN_H_FILES+=	/dev/null
.    for FILE in ${_ENDIAN_H_FILES}
.      if exists(${FILE})
_ENDIAN_H?=		${FILE:S/\/usr\/include\///}
.      endif
.    endfor
MACHINE_ENDIAN!=							\
	if (								\
		${ECHO} "\#include <${_ENDIAN_H}>";			\
		${ECHO} "\#ifndef BYTE_ORDER";				\
		${ECHO} "\#ifdef _BIG_ENDIAN";				\
		${ECHO} "\#define BYTE_ORDER 4321";			\
		${ECHO} "\#else";					\
		${ECHO} "\#define BYTE_ORDER 1234";			\
		${ECHO} "\#endif";					\
		${ECHO} "\#endif";					\
		${ECHO} "BYTE_ORDER";					\
	   ) | ${CC} -E - | ${GREP} "4321" >/dev/null 2>&1;		\
	then								\
		${ECHO} big;						\
	else								\
		${ECHO} little;						\
	fi
MAKEFLAGS+=	MACHINE_ENDIAN="${MACHINE_ENDIAN}"
.  endif
_MAME_CPU.big-endian=		risc
_MAME_CPU.little-endian=	risc_lsb
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

.if exists({${X11BASE}/include/X11/extensions/xf86dga.h)
MAKE_FLAGS+=		X11_DGA=1
.endif

# If supported, add appropriate definitions to build joystick drivers.
.if exists(/usr/include/machine/joystick.h) ||				\
    exists(/usr/include/linux/joystick.h)
MAKE_FLAGS+=		JOY_I386=1
.endif
.if ${OPSYS} == "NetBSD"
.  if exists(/usr/lib/libusb.a)
MAKE_FLAGS+=		JOY_USB=1
.  endif
.endif

OWN_DIRS=		${SPOOLDIR}

post-configure:
	cd ${WRKSRC}/doc;						\
	${SED}	-e "s|@ROMPATH@|${ROMPATH}|g"				\
		-e "s|@SPOOLDIR@|${SPOOLDIR}|g"				\
		${TARGET}rc.dist > ${TARGET}rc
.if ${MAKE_FLAGS:M*USB*} != ""
	${LN} -fs /usr/include/usb.h ${BUILDLINK_DIR}/include
	for FILE in /usr/lib/libusb*; do				\
	  ${LN} -fs $$FILE ${BUILDLINK_DIR}/lib;			\
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${TARGET}.${MAME_DISP_METHOD}	\
		${PREFIX}/bin/${TARGET}
	${INSTALL_MAN} ${WRKSRC}/doc/${TARGET}.6			\
		${PREFIX}/man/man6/${TARGET}.6
	${INSTALL_DATA_DIR} ${ROMPATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${TARGET}rc ${ROMPATH}/${TARGET}rc

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
