# $Id: optimize_gcc.mk,v 1.36 2009/04/21 16:47:48 tnn Exp $

# This file is 'experimental' - which is doublespeak for unspeakably
# ugly, and quite broken by design.
#
# The intention is to pass additional flags to gcc to further optimise
# generated code. It _will_ make it impossible to debug, may fail to
# compile some code, and even generate curdled binaries. It is completely
# unsupported. Any questions should be directed to <abs@absd.org>.

.ifdef BSD_PKG_MK			# Try to catch various package opts

# -----------------------------------------------------------------------------
# Per package exclusions

# firefox-1: v1.0, NetBSD i386/2.0
PKG_EXCLUDE_OMIT_FRAME_POINTER+=www/firefox
PKG_EXCLUDE_FAST_MATH+=www/firefox

# seamonkey-1.0.5: gcc-4.1.2 NetBSD 4.99.3 i386
PKG_EXCLUDE_OMIT_FRAME_POINTER+=www/seamonkey www/seamonkey-gtk1

PKG_EXCLUDE_OMIT_FRAME_POINTER+=mail/thunderbird mail/thunderbird-gtk1
PKG_EXCLUDE_OMIT_FRAME_POINTER+=mail/thunderbird15 mail/thunderbird15-gtk1

PKG_EXCLUDE_OMIT_FRAME_POINTER+=lang/lua
PKG_EXCLUDE_OMIT_FRAME_POINTER+=lang/ruby18-base        # NetBSD i386/3.0

# perl5: '49/49!=1 in test'
PKG_EXCLUDE_FAST_MATH+=lang/perl5

PKG_EXCLUDE_INLINE_FUNCTIONS+=emulators/qemu net/userppp multimedia/vlc

# binutils-2.17: Linux 2.6.21.5 i686, gcc-4.1.3
PKG_EXCLUDE_INLINE_FUNCTIONS+=cross/binutils devel/binutils

# procmail-3.22: debian_linux-2.6.21.5/gcc-4.1.3, gcc-4.1.2 NetBSD 4.0_BETA2
PKG_EXCLUDE_INLINE_FUNCTIONS+=mail/procmail

# aspell-0.60.5: gcc-4.1.2 NetBSD 4.0_BETA2 i386
PKG_EXCLUDE_INLINE_FUNCTIONS+=textproc/aspell

# gcc3.3.3 NetBSD i386/3.0 breaks kde3
PKG_EXCLUDE_FAST_MATH+=x11/qt3-libs

# gcc4.1.3 NetBSD i386/4.99.29 breaks liboil
PKG_EXCLUDE_OMIT_FRAME_POINTER+=devel/liboil

# -----------------------------------------------------------------------------
# Assign default flags, then remove values based on settings above
#
COPT_FLAGS=-finline-functions -fomit-frame-pointer -ffast-math

.if !empty(PKG_EXCLUDE_OMIT_FRAME_POINTER:M${PKGPATH})
COPT_FLAGS:=    ${COPT_FLAGS:S/-fomit-frame-pointer//}
.endif

.if !empty(PKG_EXCLUDE_INLINE_FUNCTIONS:M${PKGPATH})
COPT_FLAGS:=    ${COPT_FLAGS:S/-finline-functions//}
.endif

.if !empty(PKG_EXCLUDE_FAST_MATH:M${PKGPATH})
COPT_FLAGS:=    ${COPT_FLAGS:S/-ffast-math//}
.endif

CFLAGS+=${COPT_FLAGS}
CXXFLAGS+=${COPT_FLAGS}
MAKE_FLAGS+=CCOPTIONS="${COPT_FLAGS}"	# Override CCOPTIONS for imake

.else	# (BSD_PKG_MK) Assume in NetBSD base system, only COPTS

.if ${USETOOLS:Uyes} == "no"
COPT_FLAGS+=-fomit-frame-pointer
# Include ${DEFCOPTS} and set ?= to allow overriding in kernel builds
.if !defined(COPTS)
COPTS=${DEFCOPTS} ${COPT_FLAGS}
.else
COPTS+=${COPT_FLAGS}
.endif
.endif

.endif
