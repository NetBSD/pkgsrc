# $Id: optimize_gcc.mk,v 1.27 2006/02/04 15:08:33 abs Exp $

# This file is 'experimental' - which is doublespeak for unspeakably
# ugly, and quite broken by design.
#
# The intention is to pass additional flags to gcc to further optimise
# generated code. It _will_ make it impossible to debug, may fail to
# compile some code, and even generate curdled binaries. It is completely
# unsupported. Any questions should be directed to <abs@absd.org>.

# -O3 would give -finline-functions and -frename-registers
# As of gcc3-3.3nb4 -frename-registers still causes problems with xdm

.ifdef BSD_PKG_MK			# Try to catch various package opts

# This is a horrible mess, but how else to adjust per package?

COPT_FLAGS=-finline-functions -fomit-frame-pointer -ffast-math 

PKG_EXCLUDE_OMIT_FRAME_POINTER+=firefox firefox-gtk1 galeon galeon-devel
PKG_EXCLUDE_OMIT_FRAME_POINTER+=lua lua4 mozilla mozilla-gtk2
PKG_EXCLUDE_OMIT_FRAME_POINTER+=thunderbird thunderbird-gtk1
PKG_EXCLUDE_OMIT_FRAME_POINTER+=-base	# ruby18-base - NetBSD i386/3.0
PKG_EXCLUDE_INLINE_FUNCTIONS+=qemu userppp vlc
PKG_EXCLUDE_FAST_MATH+=firefox firefox-gtk1 # v1.0, NetBSD i386/2.0
PKG_EXCLUDE_FAST_MATH+=qt3-libs     # gcc3.3.3, NetBSD i386/3.0, breaks kde3

CPUFLAGS_PKGNAME:=${PKGNAME:?${PKGNAME}:${DISTNAME}}
CPUFLAGS_PKGBASE:=${PKGBASE:?${PKGBASE}:${CPUFLAGS_PKGNAME:C/-[^-]*$//}}

.if !empty(PKG_EXCLUDE_OMIT_FRAME_POINTER:M${CPUFLAGS_PKGBASE})
COPT_FLAGS:=    ${COPT_FLAGS:S/-fomit-frame-pointer//}
.endif

.if !empty(PKG_EXCLUDE_INLINE_FUNCTIONS:M${CPUFLAGS_PKGBASE})
COPT_FLAGS:=    ${COPT_FLAGS:S/-finline-functions//}
.endif

.if !empty(PKG_EXCLUDE_FAST_MATH:M${CPUFLAGS_PKGBASE})
COPT_FLAGS:=    ${COPT_FLAGS:S/-ffast-math//}
.endif

CFLAGS+=${COPT_FLAGS}
CXXFLAGS+=${COPT_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${COPT_FLAGS}"	# Override CCOPTIONS for imake

.else					# Assume in base system, only COPTS

.if ${USETOOLS:Uyes} == "no"
COPT_FLAGS+=-fomit-frame-pointer
# Include ${DEFCOPTS} and set ?= to allow overriding in kernel builds
.if !defined(COPTS)
COPTS=${DEFCOPTS} ${COPT_FLAGS}
.else
COPTS+=${COPT_FLAGS}
.endif
.endif

.if defined(USE_GCC3)
DEFWARNINGS=no
.endif

.endif
