# $NetBSD: Makefile,v 1.100 2003/09/20 00:45:26 kristerw Exp $
#

DISTNAME=		xmame-0.74.1
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old arcade machines

RESTRICTED=		"selling is not allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
MAKEFILE=		makefile.unix
TARGET=			${PKGBASE}
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.prefs.mk"

ROMPATH=		${PREFIX}/share/${TARGET}
SPOOLDIR=		/var/games/${TARGET}

MAKE_FLAGS+=		TARGET="${TARGET:S/x//}"
MAKE_FLAGS+=		LIBS="${LDFLAGS} ${LIBS}"
MAKE_FLAGS+=		CFLAGS="${CFLAGS}"
MAKE_FLAGS+=		X11INC= X11LIB=
MAKE_FLAGS+=		SOUND_ESOUND=1

MAME_DISP_METHOD?=	x11

# Determine which CPU-specific code to use.
.for MARCH in alpha m68k i386 ia64
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
.if exists(${X11BASE}/include/X11/extensions/Xv.h)
MAKE_FLAGS+=		X11_XV=1
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
		${TARGET}rc.dist > ${TARGET}rc
.if !empty(MAKE_FLAGS:M*USB*)
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

.include "../../audio/esound/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
