# $NetBSD: Makefile,v 1.128 2005/05/12 22:35:18 kristerw Exp $
#

DISTNAME=		xmame-0.96
CATEGORIES=		emulators games x11
MASTER_SITES=		http://x.mame.net/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://x.mame.net/
COMMENT=		X11 emulator for old arcade machines

RESTRICTED=		"selling is not allowed"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_PKGINSTALL=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
MAKEFILE=		makefile.unix
TARGET=			${PKGBASE}
UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

ROMPATH=		${PREFIX}/share/${TARGET}
SPOOLDIR=		${VARBASE}/games/${TARGET}

MAKE_FLAGS+=		TARGET="${TARGET:S/x//}"
MAKE_FLAGS+=		LIBS="${LDFLAGS} ${LIBS}"
MAKE_FLAGS+=		CFLAGS="${CFLAGS}"
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
MAKE_FLAGS+=		JOY_STANDARD=1
.endif
.if ${OPSYS} == "NetBSD"
.  if exists(/usr/lib/libusb.a) || exists(/usr/lib/libusbhid.a)
MAKE_FLAGS+=		JOY_USB=1
.  endif
.endif

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-2*)
# Prevent memory explosion for gcc 2.95 and older.
MAKE_FLAGS+=		LOW_MEM=1
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
	${INSTALL_PROGRAM} ${WRKSRC}/romcmp ${PREFIX}/bin/romcmp
	${INSTALL_PROGRAM} ${WRKSRC}/chdman ${PREFIX}/bin/chdman
	${INSTALL_PROGRAM} ${WRKSRC}/xml2info ${PREFIX}/bin/xml2info
	${INSTALL_MAN} ${WRKSRC}/doc/${TARGET}.6			\
		${PREFIX}/man/man6/${TARGET}.6
	${INSTALL_DATA_DIR} ${ROMPATH}
	${INSTALL_DATA} ${WRKSRC}/doc/${TARGET}rc ${ROMPATH}/${TARGET}rc
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/html/xmame/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/html/xmame/
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/xmame
	${INSTALL_DATA} ${WRKSRC}/doc/xmame-doc.txt ${PREFIX}/share/doc/xmame

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
