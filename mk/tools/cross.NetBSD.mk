# $NetBSD: cross.NetBSD.mk,v 1.1 2024/04/12 19:53:25 riastradh Exp $
#
# Cross-compiler toolchain for the NetBSD operating system.  Requires
# TOOLDIR to match build.sh for a NetBSD build.

TOOLS_PLATFORM.install?=	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-install
TOOLS_PLATFORM.readelf?=	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-readelf
TOOLS_PLATFORM.strip?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-strip

.for _t_ in ar as ld nm objcopy objdump ranlib readelf strip
TOOLS_PATH.${MACHINE_GNU_PLATFORM}-${_t_}?=	\
	${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-${_t_}
TOOLS_CREATE+=	${MACHINE_GNU_PLATFORM}-${_t_}
.endfor

TOOLS_PATH.ar?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ar
TOOLS_CREATE+=			ar
TOOLS_PATH.ranlib?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ranlib
TOOLS_CREATE+=			ranlib
TOOLS_PATH.readelf?=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-readelf
TOOLS_CREATE+=			readelf

CC=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-gcc
CXX=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-g++
LD=		${TOOLDIR}/bin/${MACHINE_GNU_PLATFORM}-ld
